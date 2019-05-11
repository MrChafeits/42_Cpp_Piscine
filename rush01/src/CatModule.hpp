#ifndef CATMODULE_HPP
#define CATMODULE_HPP

#include "IMonitorModule.hpp"

class CatModule: public IMonitorModule {

public:
	CatModule(void);
	CatModule(CatModule const&);
	~CatModule(void);
	CatModule& operator=(CatModule const&);

private:

};

#endif /* CATMODULE_HPP */
