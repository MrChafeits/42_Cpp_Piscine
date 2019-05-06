#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class Character: public ICharacter {

public:
	Character( void );
	Character( Character const & );
	~Character( void );
	Character& operator=( Character const& );

private:

};

#endif /* CHARACTER_HPP */
