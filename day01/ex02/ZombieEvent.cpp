#include "Zombie.hpp"
#include "ZombieEvent.hpp"

std::string ZombieEvent::_zombieType = "Regular";

void ZombieEvent::setZombieType( std::string t ) { _zombieType = t; }

Zombie *ZombieEvent::newZombie( std::string n )
{
	Zombie *z = new Zombie(n);
	z->setType(_zombieType);
	return z;
}

Zombie *ZombieEvent::newZombie( void )
{
	Zombie *z = new Zombie();
	z->setType(_zombieType);
	return z;
}

Zombie *ZombieEvent::randomChump( void )
{
	Zombie *z = newZombie();
	z->announce();
	return z;
}

