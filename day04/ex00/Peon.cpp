#include "Peon.hpp"

Peon::Peon( void ) { }

Peon::Peon( std::string const& n ): _name(n)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon( Peon const &cp ) { *this = cp; }

Peon::~Peon( void ) { std::cout << "Bleuark..." << std::endl; }

Peon& Peon::operator=( Peon const& ob )
{
	if (this != &ob) _name = ob.getName();
	return *this;
} // TODO: implement

void Peon::getPolymorphed( void ) const
{
	std::cout << _name
			  << " has been turned into a pink pony !" << std::endl;
}

std::string const& Peon::getName( void ) const { return _name; }

void Peon::setName( std::string const& n ) { _name = n; }
