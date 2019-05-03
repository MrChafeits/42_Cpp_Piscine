#include "PowerFist.hpp"

std::string PowerFist::_dname = std::string("PowerFist");

PowerFist::PowerFist( void ): AWeapon(_dname, 50, 8) { }

PowerFist::PowerFist( PowerFist const &cp ) { *this = cp; }

PowerFist::~PowerFist( void ) { }

PowerFist& PowerFist::operator=( PowerFist const& ) { return *this; } // TODO: implement

void PowerFist::attack( void ) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
