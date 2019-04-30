#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {

public:
	HumanB( void );
	HumanB( std::string, Weapon& );
	HumanB( HumanB const & );
	~HumanB( void );
	HumanB& operator=( HumanB const& );

	void attack( void ) const;
	void setWeapon( Weapon& );
	const Weapon& getWeapon( void ) const;
	void setName( std::string );
	const std::string getName( void ) const;
	
private:
	std::string _name;
	Weapon _hurty_hook;

};

#endif /* HUMANB_HPP */
