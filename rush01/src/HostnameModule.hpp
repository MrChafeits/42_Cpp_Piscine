#ifndef HOSTNAMEMODULE_HPP
#define HOSTNAMEMODULE_HPP

#include "IMonitorModule.hpp"

class HostnameModule: public IMonitorModule {

public:
	HostnameModule( void );
	HostnameModule( HostnameModule const & );
	~HostnameModule( void );
	HostnameModule& operator=( HostnameModule const& );

private:

};

#endif /* HOSTNAMEMODULE_HPP */
