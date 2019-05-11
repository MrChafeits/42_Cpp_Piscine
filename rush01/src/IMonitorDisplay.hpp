#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

#include "IMonitorModule.hpp"
//TODO: figure out commonalities between cli and gui display modes, if any

class IMonitorDisplay {

public:
	IMonitorDisplay(void);
	IMonitorDisplay(IMonitorDisplay const&);
	~IMonitorDisplay(void);
	IMonitorDisplay& operator=(IMonitorDisplay const&);
	virtual std::vector<IMonitorModule*> getInfo(void) const=0;

};

#endif /* IMONITORDISPLAY_HPP */
