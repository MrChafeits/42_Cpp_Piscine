#ifndef MEMORYMODULE_HPP
#define MEMORYMODULE_HPP

#include "IMonitorModule.hpp"

class MemoryModule: public IMonitorModule {

public:
	MemoryModule(void);
	MemoryModule(MemoryModule const&);
	~MemoryModule(void);
	MemoryModule& operator=(MemoryModule const&);

private:

};

#endif /* MEMORYMODULE_HPP */
