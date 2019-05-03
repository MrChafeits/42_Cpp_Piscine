#include "RadScorpion.hpp"

std::string RadScorpion::_dtype = std::string("RadScorpion");

RadScorpion::RadScorpion( void ): Enemy(80, _dtype)
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion( RadScorpion const &cp ) { *this = cp; }

RadScorpion::~RadScorpion( void ) { }

RadScorpion& RadScorpion::operator=( RadScorpion const& ) { return *this; }

void RadScorpion::takeDamage( int n )
{
	if (!_hp) {
		std::cout << "Enemy " << _type << " is a pile of meaty bones." << std::endl;
	} else {
		std::cout << "Enemy " << _type << " takes " << (n-3<0?0:n-3) << " damage." << std::endl;
		_hp -= (n-3<0?0:n-3);
		if (_hp<=0) {
			_hp=0;
			std::cout << "* SPROTCH *" << std::endl;
		}
	}
}
