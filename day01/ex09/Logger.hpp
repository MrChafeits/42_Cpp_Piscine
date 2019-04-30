#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class Logger {

public:
	Logger( void );
	~Logger( void );

	void log( std::string const&, std::string const& );

private:
	void logToConsole( std::string const& );
	void logToFile( std::string const& );
	std::string makeLogEntry( std::string const& );

};

#endif /* LOGGER_HPP */
