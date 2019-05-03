#include "AWeapon.hpp"
std::string AWeapon::_dname = std::string("Shoot");
AWeapon::AWeapon( void ): _name(_dname), _dmg(20), _apc(5) { }

AWeapon::AWeapon( std::string const& n, int d, int a ): _name(n), _dmg(d), _apc(a)
{ }

AWeapon::AWeapon( AWeapon const &cp ):
	_name(cp.getName()),
	_dmg(cp.getDamage()),
	_apc(cp.getAPCost())
{
	*this = cp;
}

AWeapon::~AWeapon( void ) { }

AWeapon& AWeapon::operator=( AWeapon const& ) { return *this; } // TODO: implement

std::string const& AWeapon::getName( void ) const { return _name; }
int AWeapon::getAPCost( void ) const { return _apc; }
int AWeapon::getDamage( void ) const { return _dmg; }
