#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA( std::string n, Weapon &w ): _name(n), _hurty_hook(w)
{
};

HumanA::~HumanA( void ) { }

void HumanA::setWeapon( Weapon &w ) { this->_hurty_hook = w; }

Weapon &HumanA::getWeapon( void ) const { return this->_hurty_hook; }

void HumanA::setName( std::string s ) { this->_name = s; }

const std::string HumanA::getName( void ) const { return this->_name; }

void HumanA::attack( void ) const
{
	std::cout << this->_name
			  << " attacks with their "
			  << this->_hurty_hook.getType()
			  << std::endl;
}
