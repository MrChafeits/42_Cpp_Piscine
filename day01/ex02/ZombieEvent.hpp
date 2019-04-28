#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include "Zombie.hpp"
#include <iostream>
#include <string>

class ZombieEvent {

public:
	ZombieEvent( void );
	~ZombieEvent( void );
	static Zombie *newZombie( std::string n );
	static Zombie *newZombie( void );
	static Zombie *randomChump( void );
	static void setZombieType( std::string t );
	static std::string getZombieType( void );

private:
	static std::string _zombieType;
	static std::random_device rd;

};

void a();

#endif
