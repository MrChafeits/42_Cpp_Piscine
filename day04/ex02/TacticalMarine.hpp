#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP

#include <iostream>
#include <string>
#include "ISpaceMarine.hpp"

class TacticalMarine: public ISpaceMarine {

public:
	TacticalMarine( void );
	TacticalMarine( TacticalMarine const & );
	~TacticalMarine( void );
	TacticalMarine& operator=( TacticalMarine const& );

	TacticalMarine* clone( void ) const;
	void battleCry( void ) const;
	void rangedAttack( void ) const;
	void meleeAttack( void ) const;

private:

};

#endif /* TACTICALMARINE_HPP */
