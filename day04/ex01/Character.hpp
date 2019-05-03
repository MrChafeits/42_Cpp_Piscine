#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"

class Character {

public:
	Character( void );
	Character( std::string const& );
	Character( Character const & );

	virtual ~Character( void );

	Character& operator=( Character const& );

	void recoverAP( void );
	void equip( AWeapon* );
	void attack( Enemy* );

	std::string const& getName( void ) const;
	int getAp( void ) const;
	AWeapon const *getWep( void ) const;

private:
	std::string const& _name;
	int _ap;
	AWeapon* _wep;
	static std::string _dname;

};

std::ostream& operator<<( std::ostream&, Character const& );

#endif /* CHARACTER_HPP */
