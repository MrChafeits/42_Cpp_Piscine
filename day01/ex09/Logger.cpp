#include "Logger.hpp"

Logger::Logger( void ) { }

Logger::Logger( Logger const &cp ) { *this = cp; }

Logger::~Logger( void ) { }

Logger& Logger::operator=( Logger const& ) { return *this; } // TODO: implement
