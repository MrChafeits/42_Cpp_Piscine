#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

//TODO: figure out commonalities between cli and gui display modes, if any

class IMonitorDisplay {

public:
	IMonitorDisplay(void);
	IMonitorDisplay(IMonitorDisplay const&);
	~IMonitorDisplay(void);
	IMonitorDisplay& operator=(IMonitorDisplay const&);

private:
	bool _visible;
	int _xPos;
	int _yPos;
	int _width;
	int _height;

};

#endif /* IMONITORDISPLAY_HPP */
