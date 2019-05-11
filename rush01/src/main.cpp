#include "IMonitorModule.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <stdint.h>
#include <curses.h>
// honk
#include <unistd.h>

// Ram?
#include <mach/mach_init.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>

// Network Module headers
#include <sys/sysctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <net/if_dl.h>
#include <net/route.h>

// File System Module headers -- BONUS
#include <sys/mount.h>
#include <sys/wait.h>
#include <IOKit/storage/IOMediaBSDClient.h>

// Uptime Monitor Module headers -- BONUS?
#include <sys/sysctl.h>

// Hostname Module headers
#include <sys/utsname.h>

/* TODO: Modules
PART 1:
	- Hostname/username Module
	  sysctl() is the thing to use here
	- OS Info Module
	  and here as well for sysctl()
	- Date/time Module
PART 2:
	- CPU Module (Model, clock speed, number of cores, activity, cpuid stuff...)
	- RAM Module
PART 3:
	- Network Activity Module
PART 4:
	- More Modules!
	- Bonus module: zaz's favorite animal is the common domestic Cat
*/

typedef unsigned long ulong;
// typedef unsigned int uint;
char* disp_hostname(void) {
	static char buf[256];
	if (gethostname(buf, sizeof(buf)) != 0)
		strcpy(buf, "unknown");
	return buf;
}

char* disp_sysname(void) {
	static char sname[514];
	char* tmp;
	struct utsname utsn;
	if (!*sname && uname(&utsn) > -1) {
		tmp = strcpy(sname, utsn.sysname);
		*tmp = ' ';
		*(tmp+1) = 0;
		strcpy(tmp+1, utsn.release);
	}
	if (!*sname) {
		strcpy(sname, "unknown name");
	}
	return sname;
}

/* CPU Module Info Prototype */
struct CpuMon {
	char* name;
	char* panel_label;
	// GtkWidget *vbox;
	// GkrellmChart* chart;
	// GkrellmChartconfig* chart_config;
	// GkrellmChartdata* sys_cd;
	// GkrellmChartdata* user_cd;
	// GkrellmChartdata*  nice_cd;
	int enables;
	int extra_info;
	int is_composite;
	ulong previous_total;
	int instance;
	void* sensor_temp;
	void* sensor_fan;
	// GkrellmDecal* sensor_decal;
	// GkrellmDecal* fan_decal;
	bool show_temp;
	bool show_fan;
	bool new_text_fmt;
	int save_label_pos;
	// GkrellmAlert* alert;
	ulong prev_alert_val;
	ulong prev_alert_total;
	// GkrellmLauncher launch
	// GtkWidget* launch_entry;
	// GtkWidget* tooltip_entry;
	ulong user;
	ulong nice;
	ulong sys;
	ulong idle;
};

static unsigned n_cpus;
std::vector<CpuMon*> cpu_mon_list;
void gkrellm_cpu_assign_data(uint n, ulong user, ulong nice, ulong sys, ulong idle) {
	if (cpu_mon_list.size() < n_cpus) {
		CpuMon* cpu = new CpuMon();
		cpu->user = user;
		cpu->nice = nice;
		cpu->sys = sys;
		cpu->idle = idle;
		cpu_mon_list.push_back(cpu);
	} else {
		cpu_mon_list[n]->user = user;
		cpu_mon_list[n]->nice = nice;
		cpu_mon_list[n]->sys = sys;
		cpu_mon_list[n]->idle = idle;
	}
}

void disp_sys_cpu_read_data(void) {
	processor_cpu_load_info_data_t *pinfo; // basically a uint[4] on these systems
	mach_msg_type_number_t info_count;
	uint i;
	if (host_processor_info(mach_host_self(),
		PROCESSOR_CPU_LOAD_INFO,
		&n_cpus,
		(processor_info_array_t*)&pinfo,
		&info_count) != KERN_SUCCESS) { return; }
	for (i=0; i < n_cpus; i++) {
		gkrellm_cpu_assign_data(i,
			pinfo[i].cpu_ticks[CPU_STATE_USER],
			pinfo[i].cpu_ticks[CPU_STATE_NICE],
			pinfo[i].cpu_ticks[CPU_STATE_SYSTEM],
			pinfo[i].cpu_ticks[CPU_STATE_IDLE]);
	}
	vm_deallocate(mach_task_self(), (vm_address_t)pinfo, info_count);
}

int _yMax=0,_xMax=0;
void init_display() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	getmaxyx(stdscr, _yMax, _xMax);
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
}

bool display() {
	int ch=0,inpt=0;
	uint i;
	{
		mvprintw(2,0,"hostname = \'%s\'", disp_hostname());
		mvprintw(3,0,"sysname = \'%s\'", disp_sysname());
	}
	ch = getch();
	inpt = ch!=ERR ? ch : -1;
	switch (ch) {
		case 'q': case '\e': return true;
		default: break;
	}
	disp_sys_cpu_read_data();
	for (i=0; i < cpu_mon_list.size(); i++) {
		mvprintw(5+i,0,"cpu_mon_list[%d] = user %lu sys %lu idle %lu nice %lu",i, cpu_mon_list[i]->user,
			cpu_mon_list[i]->sys, cpu_mon_list[i]->idle, cpu_mon_list[i]->nice);
	}
	{
		// static int oid_proc[3] = {CTL_KERN, KERN_PROC, KERN_PROC_ALL};
		// static uint n_processes, n_forks=0;
		// uint n_vforks, n_rforks;
		// int r_forks, r_vforks, r_rforks;
		// size_t len;
		// double avenrun;
		// if (getloadavg(&avenrun, 1) <= 0) avenrun = 0;
		// if (sysctl(oid_proc, 3, NULL, &len, NULL, 0) >= 0)
		// 	n_processes = len / sizeof(struct kinfo_proc);
	}
	return false;
}

int main(int, char*[]) {
	init_display();
	while (true)
		if (display())
			break;
	endwin();
	return 0;
}
