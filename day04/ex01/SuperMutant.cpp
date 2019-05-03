#include "SuperMutant.hpp"

std::string SuperMutant::_dtype = std::string("SuperMutant");

SuperMutant::SuperMutant( void ): Enemy(170, _dtype)
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant( SuperMutant const &cp ) { *this = cp; }

SuperMutant::~SuperMutant( void ) { }

SuperMutant& SuperMutant::operator=( SuperMutant const& ) { return *this; }

void SuperMutant::takeDamage( int n )
{
	if (!_hp) {
		std::cout << "Enemy " << _type << " is a pile of meaty bones." << std::endl;
	} else {
		std::cout << "Enemy " << _type << " takes " << (n-3<0?0:n-3) << " damage." << std::endl;
		_hp -= (n-3<0?0:n-3);
		if (_hp<=0) {
			_hp=0;
			std::cout << "Aaargh ..." << std::endl;
		}
	}
}
