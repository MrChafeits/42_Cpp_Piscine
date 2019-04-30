#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA( void )
{
	this->_name = "John SpaceMarine";
	this->_hurty_hook = Weapon("schuut");
}

HumanA::HumanA( std::string n, Weapon &w ): _name(n), _hurty_hook(w) { };

HumanA::HumanA( HumanA const &cp ) { *this = cp; }

HumanA::~HumanA( void ) { }

HumanA& HumanA::operator=( HumanA const& ) { return *this; }	// TODO: implement

void HumanA::setWeapon( Weapon& w ) { this->_hurty_hook = w; }

const Weapon& HumanA::getWeapon( void ) const { return this->_hurty_hook; }

void HumanA::setName( std::string s ) { this->_name = s; }

const std::string HumanA::getName( void ) const { return this->_name; }

void HumanA::attack( void ) const
{
	std::cout << this->_name
			  << " attacks with their "
			  << this->_hurty_hook.getType()
			  << std::endl;
}
