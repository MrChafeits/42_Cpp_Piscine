#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
	_hp = 100;
	_hpMax = 100;
	_ep = 50;
	_epMax = 50;
	_meleeDmg = 20;
	_rangedDmg = 15;
	_lvl = 1;
	_name = "Shifto";
	_armorDmgResist = 3;
	std::cout << "LOADING ";
	funnyScream();
	std::cout << ".initramfs..................DONE" << std::endl;
	std::cout << "LOADING " << _name << ".squashfs...........DONE" << std::endl;
	std::cout << "START UP SEQUENCE COMPLETE" << std::endl << std::endl;
}

ScavTrap::ScavTrap( std::string& name )
{
	_hp = 100;
	_hpMax = 100;
	_ep = 50;
	_epMax = 50;
	_meleeDmg = 20;
	_rangedDmg = 15;
	_lvl = 1;
	_name = name;
	_armorDmgResist = 3;
	std::cout << "LOADING ";
	funnyScream();
	std::cout << ".initramfs..................DONE" << std::endl;
	std::cout << "LOADING " << _name << ".squashfs...........DONE" << std::endl;
	std::cout << "START UP SEQUENCE COMPLETE" << std::endl << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &cp )
{
	funnyScream();
	std::cout << " RUNNING JOB \"sudo cp -R / /mnt/NEW/\"..............";
	std::cout << "DONE" << std::endl;
	*this = cp;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "INITIATING ";
	funnyScream();
	std::cout << " SHUT DOWN SEQUENCE" << std::endl;
}

ScavTrap& ScavTrap::operator=( ScavTrap const& beep )
{
	funnyScream();
	std::cout << " RUNNING JOB "
			  << "\"sudo dd of=/dev/sda if=/dev/sds\"..............";
	_hp = beep.getHp();
	_hpMax = beep.getHpMax();
	_ep = beep.getEp();
	_epMax = beep.getEpMax();
	_lvl = beep.getLvl();
	_name = beep.getName();
	_meleeDmg = beep.getMeleeDmg();
	_rangedDmg = beep.getRangedDmg();
	_armorDmgResist = beep.getArmorDmgResist();
	std::cout << "DONE" << std::endl;
	return *this;
}

std::string _challenges[8] = {
	" to a race with Koopa The Quick",
	" to a game of Full Contact Chess",
	" to a game of Cross Country Bowling",
	" to a Poetry Slam, to the death",
	" to a Code Review",
	" to a Mathletes Tournament Cage Match",
	" to a Presidential Election",
	" to a Civil Suit in Kangaroo Court",
};

void ScavTrap::challengeNewcomer( const std::string& target )
{
	if (!_hp) {
		funnyScream();
		std::cout << " [" << _name << "] IS DED" << std::endl;
	} else {
		if (_ep >= 25) {
			funnyScream();
			std::cout << " [" << _name
					  << "] challenges newcomer {" << target
					  << "}" << _challenges[rand()%8] << std::endl;
			_ep -= 25;
		} else {
			funnyScream();
			std::cout << " [" << _name << "] is too tired" << std::endl;
		}
	}
}

void ScavTrap::funnyScream( void ) const { std::cout << "SC4V-TP"; }
