#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP

#include <iostream>
#include <string>
#include "Enemy.hpp"

class RadScorpion: public Enemy {

public:
	RadScorpion( void );
	RadScorpion( RadScorpion const & );
	~RadScorpion( void );
	RadScorpion& operator=( RadScorpion const& );

	virtual void takeDamage( int );

private:
	static std::string _dtype;

};

#endif /* RADSCORPION_HPP */
