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

std::ostream& operator<<( std::ostream& os, Character const& ob )
{
	os << ob.getName() << " has " << ob.getAp() << " AP and ";
	if (ob.getWep())
		os << " wields a " << ob.getWep()->getName() << std::endl;
	else
		os << " is unarmed" << std::endl;
	return os;
}
