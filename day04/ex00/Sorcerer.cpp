#include "Sorcerer.hpp"

Sorcerer::Sorcerer( void ): _name("Motherfucker"), _title("dotOBJ")
{
}

Sorcerer::Sorcerer( std::string const& n, std::string const& t ): _name(n), _title(t)
{
	std::cout << _name << ", " << _title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer( Sorcerer const &cp ) { *this = cp; }

Sorcerer::~Sorcerer( void )
{
	std::cout << _name
			  << ", "
			  << _title
			  << ", is dead. Consequences will never be the same !"
			  << std::endl;
}

Sorcerer& Sorcerer::operator=( Sorcerer const& ob )
{
	_name = ob.getName();
	_title = ob.getTitle();
	return *this;
} // TODO: implement

std::ostream& operator<<( std::ostream& os, Sorcerer const& ob )
{
	os << "I am "
	   << ob.getName()
	   <<  ", "
	   << ob.getTitle()
	   << " and I like ponies !"
	   << std::endl;
	return os;
}

void Sorcerer::polymorph( Victim const& v ) const { v.getPolymorphed(); }
void Sorcerer::polymorph( Peon const& p ) const { p.getPolymorphed(); }

std::string const& Sorcerer::getName( void ) const { return _name; }
std::string const& Sorcerer::getTitle( void ) const { return _title; }

void Sorcerer::setName( std::string const& n ) { _name = n; }
void Sorcerer::setTitle( std::string const& t ) { _title = t; }
