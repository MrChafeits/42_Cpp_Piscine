#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int main( void )
{
	Character *jahn = new Character("Schuut");
	std::cout << *jahn;
	Enemy* b = new RadScorpion();
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
	jahn->attack(b);
	jahn->attack(b);
	jahn->attack(b);
	jahn->recoverAP();
	std::cout << *jahn;
}
