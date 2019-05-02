#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include <iostream>
#include <string>
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : virtual public NinjaTrap, virtual public FragTrap {

public:
	SuperTrap( void );
	SuperTrap( std::string& );
	SuperTrap( const SuperTrap& );
	~SuperTrap( void );
	SuperTrap& operator=( const SuperTrap& );

	void challengeNewcomer( const std::string& );
	virtual void funnyScream( void ) const;
	
};

#endif /* SUPERTRAP_HPP */
