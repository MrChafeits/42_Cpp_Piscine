#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main( void )
{
	Zombie nick = Zombie("Nick");
	Zombie *z1 = ZombieEvent::randomChump();

	ZombieEvent::setZombieType("Spinning");
	Zombie *z2 = ZombieEvent::randomChump();
	delete z1;
	delete z2;
	nick.announce();
}
