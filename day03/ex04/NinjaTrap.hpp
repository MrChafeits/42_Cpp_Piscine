#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap {

public:
	NinjaTrap( void );
	NinjaTrap( std::string& );
	NinjaTrap( const NinjaTrap& );
	~NinjaTrap( void );
	NinjaTrap& operator=( const NinjaTrap& );

	void ninjaShoebox( ClapTrap& );
	void ninjaShoebox( FragTrap& );
	void ninjaShoebox( ScavTrap& );
	void ninjaShoebox( NinjaTrap& );
	virtual void funnyScream( void ) const;

};

#endif /* NINJATRAP_HPP */
