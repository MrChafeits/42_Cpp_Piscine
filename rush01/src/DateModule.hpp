#ifndef DATEMODULE_HPP
#define DATEMODULE_HPP

#include "IMonitorModule.hpp"

class DateModule: public IMonitorModule {

public:
	DateModule(void);
	DateModule(DateModule const&);
	~DateModule(void);
	DateModule& operator=(DateModule const&);

private:

};

#endif /* DATEMODULE_HPP */
