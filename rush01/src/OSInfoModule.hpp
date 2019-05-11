#ifndef OSINFOMODULE_HPP
#define OSINFOMODULE_HPP

#include "IMonitorModule.hpp"

class OSInfoModule: public IMonitorModule {

public:
	OSInfoModule(void);
	OSInfoModule(OSInfoModule const&);
	~OSInfoModule(void);
	OSInfoModule& operator=(OSInfoModule const&);

private:

};

#endif /* OSINFOMODULE_HPP */
