#include "Character.hpp"

std::string Character::_dname = std::string("John Schuut");

Character::Character( void ): _name(_dname), _ap(40)
{
	_wep = nullptr;
}

Character::Character( std::string const& n ): _name(n), _ap(40)
{
	_wep = nullptr;
}

Character::Character( Character const &cp ): _name(cp._name), _ap(cp._ap)
{
	_wep = cp._wep;
	*this = cp;
}

Character::~Character( void ) { }

Character& Character::operator=( Character const& ) { return *this; } // TODO: implement

void Character::recoverAP( void ) { _ap = (_ap + 10 > 40) ? 40 : (_ap + 10); }

void Character::equip( AWeapon* w ) { _wep = w; }

void Character::attack( Enemy* e )
{
	if (_ap > _wep->getAPCost()) {
		std::cout << _name
				  << " attacks "
				  << e->getType()
				  << " with a "
				  << _wep->getName()
			 	  << std::endl;
		_ap -= _wep->getAPCost();
		_wep->attack();
		e->takeDamage(_wep->getDamage());
	}
}

std::ostream& operator<<( std::ostream& os, Character const& ob )
{
	os << ob.getName() << " has " << ob.getAp() << " AP and ";
	if (ob.getWep())
		os << " wields a " << ob.getWep()->getName() << std::endl;
	else
		os << " is unarmed" << std::endl;
	return os;
}

std::string const& Character::getName( void ) const { return _name; }
int Character::getAp( void ) const { return _ap; }
AWeapon const* Character::getWep( void ) const { return _wep; }
