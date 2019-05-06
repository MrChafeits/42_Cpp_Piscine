#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int main( void )
{
	Character *jahn = new Character("Schuut Man");
	std::cout << *jahn;
	Enemy* b = new RadScorpion(), *c = new SuperMutant();
	AWeapon *pr=new PlasmaRifle(), *pf=new PowerFist();
	jahn->equip(pr);
	std::cout << *jahn;
	jahn->equip(pf);
	jahn->attack(b);
	std::cout << *jahn;
	jahn->equip(pr);
	jahn->attack(b);
	std::cout << *jahn;
	jahn->recoverAP();
	jahn->equip(pf);
	std::cout << *jahn;
	jahn->attack(c);
	jahn->attack(c);
	jahn->attack(c);
	jahn->attack(c);
	jahn->attack(c);
	jahn->attack(c);
	jahn->recoverAP();
	std::cout << *jahn;
}
