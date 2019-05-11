#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

#include <string>
#include <vector>


class IMonitorModule {

public:
	IMonitorModule(void);
	IMonitorModule(IMonitorModule const&);
	~IMonitorModule(void);
	IMonitorModule& operator=(IMonitorModule const&);

	virtual bool toggle(void)=0;
	virtual void updateStats(void)=0;
	virtual int const& getSize(void) const=0;
	virtual int const& getHeight(void) const=0;
	virtual std::string const& getName(void) const=0;

private:
	bool _on;
	int _xPos;
	int _yPos;
	int _w;
	int _h;

};

#endif /* IMONITORMODULE_HPP */
