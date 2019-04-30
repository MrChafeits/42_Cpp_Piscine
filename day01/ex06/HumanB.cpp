#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB( void )
{
	this->_name = "Jane SpaceMarine";
	this->_hurty_hook = Weapon("schuut");
}

HumanB::HumanB( std::string n, Weapon &w ): _name(n), _hurty_hook(w) { };

HumanB::HumanB( HumanB const &cp ) { *this = cp; }

HumanB::~HumanB( void ) { }

HumanB& HumanB::operator=( HumanB const& ) { return *this; }	// TODO: implement

void HumanB::setWeapon( Weapon& w ) { this->_hurty_hook = w; }

const Weapon& HumanB::getWeapon( void ) const { return this->_hurty_hook; }

void HumanB::setName( std::string s ) { this->_name = s; }

const std::string HumanB::getName( void ) const { return this->_name; }

void HumanB::attack( void ) const
{
	std::cout << this->_name
			  << " attacks with their "
			  << this->_hurty_hook.getType()
			  << std::endl;
}
