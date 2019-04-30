#include <sstream>
#include "Brain.hpp"

Brain::Brain( void ) { this->_smort = true; }

Brain::Brain( bool sm ): _smort(sm) { }

Brain::Brain( Brain const &cp ) { *this = cp; }

Brain::~Brain( void ) { }

Brain& Brain::operator=( Brain const& ) { return *this; }	// TODO: implement

std::string Brain::identify( void ) const
{
	const void *addr = static_cast<const void*>(this);
	std::stringstream ss;
	ss << addr;
	return (ss.str());
}
