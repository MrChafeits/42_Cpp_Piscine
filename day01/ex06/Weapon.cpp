#include <string>
#include "Weapon.hpp"

Weapon::Weapon( void ) { }

Weapon::Weapon( std::string t ): _type(t) { }

Weapon::Weapon( Weapon const &cp ) { *this = cp; }

Weapon::~Weapon( void ) { }

Weapon& Weapon::operator=( Weapon const& ) { return *this; }	// TODO: implement

const std::string& Weapon::getType( void ) const
{
	return const_cast<const std::string&>(this->_type);
}

void Weapon::setType( std::string s ) { this->_type = s; }
