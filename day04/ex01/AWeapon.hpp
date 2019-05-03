#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <iostream>
#include <string>

class AWeapon {

public:
	AWeapon( void );
	AWeapon( std::string const&, int, int );
	AWeapon( AWeapon const& );
	
	virtual ~AWeapon( void );

	AWeapon& operator=( AWeapon const& );

	std::string const& getName( void ) const;
	int getAPCost( void ) const;
	int getDamage( void ) const;

	virtual void attack( void )  const = 0;

protected:
	std::string const& _name;
	int _dmg;
	int _apc;

private:
	static std::string _dname;

};

#endif /* AWEAPON_HPP */
