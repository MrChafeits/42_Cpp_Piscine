#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include <iostream>
#include <string>
#include "Enemy.hpp"

class SuperMutant: public Enemy {

public:
	SuperMutant( void );
	SuperMutant( SuperMutant const & );
	~SuperMutant( void );
	SuperMutant& operator=( SuperMutant const& );

	virtual void takeDamage( int );

private:
	static std::string _dtype;

};

#endif /* SUPERMUTANT_HPP */
