#include <string>
#include "Weapon.hpp"

Weapon::Weapon( void ) { }

Weapon::Weapon( std::string t )
{
	this->_type = t;
}

Weapon::~Weapon( void ) { }

std::string Weapon::getType( void ) const { return this->_type; }

void Weapon::setType( std::string s ) { this->_type = s; }
