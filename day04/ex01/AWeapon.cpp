#include "AWeapon.hpp"

AWeapon::AWeapon( void ) { }

AWeapon::AWeapon( std::string const& n, int d, int a ): _name(n), _dmg(d), _apc(a)
{ }

AWeapon::AWeapon( AWeapon const &cp ) { *this = cp; }

AWeapon::~AWeapon( void ) { }

AWeapon& AWeapon::operator=( AWeapon const& ) { return *this; } // TODO: implement

std::string const& AWeapon::getName( void ) const { return _name; }
int AWeapon::getAPCost( void ) const { return _apc; }
int AWeapon::getDamage( void ) const { return _dmg; }
