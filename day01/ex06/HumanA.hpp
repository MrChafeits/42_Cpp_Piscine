#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {

public:
	HumanA( void );
	HumanA( std::string, Weapon& );
	HumanA( HumanA const & );
	~HumanA( void );
	HumanA& operator=( HumanA const& );

	void attack( void ) const;
	void setWeapon( Weapon& );
	const Weapon& getWeapon( void ) const;
	void setName( std::string );
	const std::string getName( void ) const;
	
private:
	std::string _name;
	Weapon _hurty_hook;

};

#endif /* HUMANA_HPP */
