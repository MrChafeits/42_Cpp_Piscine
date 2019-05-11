#ifndef CPUMODULE_HPP
#define CPUMODULE_HPP

#include "IMonitorModule.hpp"
#include <algorithm>
#include <string>
#include <vector>
#include <stdint.h>

class CpuModule {

public:
	CpuModule(void);
	CpuModule(CpuModule const&);
	virtual ~CpuModule(void);
	CpuModule& operator=(CpuModule const&);

	std::string const& getName(void) const;
	bool getEnabled(void) const;
	uint64_t getPrevTotal(void) const;
	std::vector<std::vector<uint64_t> > const& getStats(void) const;

private:
	std::string _name;
	bool _enabled;
	// CPU Ticks [cpu#][user]
	std::vector<std::vector<uint64_t> > _cpu;
	uint64_t _prevTotal;

};

#endif /* CPUMODULE_HPP */
