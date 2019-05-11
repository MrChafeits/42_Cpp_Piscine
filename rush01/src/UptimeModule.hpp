#ifndef UPTIMEMODULE_HPP
#define UPTIMEMODULE_HPP

#include "IMonitorModule.hpp"

class UptimeModule: public IMonitorModule {

public:
	UptimeModule(void);
	UptimeModule(UptimeModule const&);
	~UptimeModule(void);
	UptimeModule& operator=(UptimeModule const&);

private:
	struct timeval _tval;
	std::string _name;

};

#endif /* UPTIMEMODULE_HPP */
