#include "Victim.hpp"

Victim::Victim( void ): _name("Joe")
{
	std::cout << "Some random victim called "
			  << _name << " just popped !" << std::endl;
}

Victim::Victim( std::string const& n ): _name(n)
{
	std::cout << "Some random victim called "
			  << _name << " just popped !" << std::endl;
}

Victim::Victim( Victim const &cp ) { *this = cp; }

Victim::~Victim( void )
{
	std::cout << "Victim " << _name
			  << " just died for no apparent reason !"
			  << std::endl;
}

Victim& Victim::operator=( Victim const& ob )
{
	_name = ob.getName();
	return *this;
} // TODO: implement

std::ostream& operator<<( std::ostream& os, Victim const& ob )
{
	os << "I'm "
	   << ob.getName()
	   << " and I like otters !"
	   << std::endl;
	return os;
}

void Victim::getPolymorphed( void ) const
{
	std::cout << _name
			  << " has been turned into a cute little sheep !" << std::endl;
}

std::string const& Victim::getName( void ) const { return _name; }

void Victim::setName( std::string const& n ) { _name = n; }
