#include "FragTrap.hpp"
#include "ScavTrap.hpp"

static const std::string targets[8] = {
	"Bad Boat",
	"Enemy Boat",
	"Hostile Boat",
	"Combative Boat",
	"Aggressive Boat",
	"Territorial Boat",
	"Antagonistic Boat",
	"Confrontational Boat",
};

void testF( void )
{
	int j=0;
	std::string n1("Vootbi");
	FragTrap bep;
	FragTrap doot(n1);
	FragTrap clank(doot);
	doot.rangedAttack(targets[rand()%8]);
	doot.meleeAttack(targets[rand()%8]);
	doot.takeDamage(75);
	doot.rangedAttack(targets[rand()%8]);
	doot.meleeAttack(targets[rand()%8]);
	doot.beRepaired(75);
	doot.rangedAttack(targets[rand()%8]);
	doot.meleeAttack(targets[rand()%8]);
	doot.takeDamage(175);
	doot.rangedAttack(targets[rand()%8]);
	doot.meleeAttack(targets[rand()%8]);
	doot.beRepaired(175);
	doot.rangedAttack(targets[rand()%8]);
	doot.meleeAttack(targets[rand()%8]);
	doot.setHp(doot.getHpMax());
	doot.setEp(doot.getEpMax());
	for (int i=0; i<8; i++) {
		doot.vaulthunter_dot_exe(targets[rand()%8]);
		if (doot.getEp() < 25 && !j) {
			j=1;
			doot.vaulthunter_dot_exe(targets[rand()%8]);
		} else if (doot.getEp() < 25 && j) {
			doot.setEp(doot.getEpMax());
			j=0;
		}
	}
}

void testS( void )
{
	int j=0;
	std::string n1("Binyot");
	ScavTrap bep;
	ScavTrap doot(n1);
	ScavTrap clank(doot);
	doot.rangedAttack(targets[rand()%8]);
	doot.meleeAttack(targets[rand()%8]);
	doot.takeDamage(75);
	doot.rangedAttack(targets[rand()%8]);
	doot.meleeAttack(targets[rand()%8]);
	doot.beRepaired(75);
	doot.rangedAttack(targets[rand()%8]);
	doot.meleeAttack(targets[rand()%8]);
	doot.takeDamage(175);
	doot.rangedAttack(targets[rand()%8]);
	doot.meleeAttack(targets[rand()%8]);
	doot.beRepaired(175);
	doot.rangedAttack(targets[rand()%8]);
	doot.meleeAttack(targets[rand()%8]);
	doot.setHp(doot.getHpMax());
	doot.setEp(doot.getEpMax());
	for (int i=0; i<8; i++) {
		doot.challengeNewcomer(targets[rand()%8]);
		if (doot.getEp() < 25 && !j) {
			doot.challengeNewcomer(targets[rand()%8]);
			j=1;
		} else if (doot.getEp() < doot.getEpMax() && j) {
			doot.setEp(doot.getEpMax());
			j=0;
		}
	}
}

int main( void )
{
	srand(time(0));
	testF();
	testS();
}
