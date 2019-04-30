#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {

public:
	HumanA( std::string, Weapon& );
	~HumanA( void );

	void attack( void ) const;
	void setWeapon( Weapon& );
	Weapon &getWeapon( void ) const;
	void setName( std::string );
	const std::string getName( void ) const;
	
private:
	std::string _name;
	Weapon &_hurty_hook;

};

#endif /* HUMANA_HPP */
