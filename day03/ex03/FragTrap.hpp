#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
	FragTrap( void );
	FragTrap( std::string& );
	FragTrap( const FragTrap& );
	~FragTrap( void );
	FragTrap& operator=( const FragTrap& );

	void vaulthunter_dot_exe( const std::string& );
	virtual void funnyScream( void ) const;

};

#endif /* FRAGTRAP_HPP */
