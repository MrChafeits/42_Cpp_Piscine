#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

#include <unistd.h>

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

class IMonitorModule {

public:
	IMonitorModule(void);
	IMonitorModule(IMonitorModule const&);
	~IMonitorModule(void);
	IMonitorModule& operator=(IMonitorModule const&);

private:
	bool _on;
	int _xPos;
	int _yPos;
	int _w;
	int _h;

};

#endif /* IMONITORMODULE_HPP */
