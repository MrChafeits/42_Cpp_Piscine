#include "Logger.hpp"

Logger::Logger( void ) { }

Logger::~Logger( void ) { }

void Logger::logToConsole( std::string const &msg )
{
	std::cout << makeLogEntry(msg) << std::endl;
}

void Logger::logToFile( std::string const &msg )
{
	std::ofstream ofs;

	ofs.open("logger.log", std::ofstream::out | std::ofstream::app);
	ofs << makeLogEntry(msg) << std::endl;
	ofs.close();
}

std::string Logger::makeLogEntry( std::string const &msg )
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	std::stringstream entry;

	entry << "[" << now << "](" << ltm->tm_year+1900 << "-"
		  << std::setfill('0') << std::setw(2) << ltm->tm_mon+1 << "-"
		  << std::setfill('0') << std::setw(2) << ltm->tm_mday << "-T"
		  << std::setfill('0') << std::setw(2) << ltm->tm_hour << ":"
		  << std::setfill('0') << std::setw(2) << ltm->tm_min << ":"
		  << std::setfill('0') << std::setw(2) << ltm->tm_sec << "):" << msg;
	return entry.str();
}

void Logger::log( std::string const &dest, std::string const &message )
{
	std::string whicharoni[2] = {"console", "file"};
	void (Logger::*fn[2])( const std::string& ) = {&Logger::logToConsole,
												   &Logger::logToFile};

	for (unsigned i = 0; i < 2; i++)
		if (dest == whicharoni[i])
			(this->*fn[i])(message);
}
