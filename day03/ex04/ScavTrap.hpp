#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:
	ScavTrap( void );
	ScavTrap( std::string& );
	ScavTrap( const ScavTrap& );
	~ScavTrap( void );
	ScavTrap& operator=( const ScavTrap& );

	void challengeNewcomer( const std::string& );
	virtual void funnyScream( void ) const;
	
};

#endif /* SCAVTRAP_HPP */
