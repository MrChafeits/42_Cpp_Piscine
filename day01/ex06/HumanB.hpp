#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {

public:
	HumanB( std::string, Weapon& );
	~HumanB( void );

	void attack( void ) const;
	void setWeapon( Weapon& );
	Weapon &getWeapon( void ) const;
	void setName( std::string );
	const std::string getName( void ) const;
	
private:
	std::string _name;
	Weapon &_hurty_hook;

};

#endif /* HUMANB_HPP */
