#include "PlasmaRifle.hpp"

std::string PlasmaRifle::_dname = std::string("PlasmaRifle");

PlasmaRifle::PlasmaRifle( void ): AWeapon(_dname, 21, 5) { }

PlasmaRifle::PlasmaRifle( PlasmaRifle const &cp ) { *this = cp; }

PlasmaRifle::~PlasmaRifle( void ) { }

PlasmaRifle& PlasmaRifle::operator=( PlasmaRifle const& ) { return *this; } // TODO: implement

void PlasmaRifle::attack( void ) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
