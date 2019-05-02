#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	_hp = 100;
	_hpMax = 100;
	_ep = 100;
	_epMax = 100;
	_meleeDmg = 30;
	_rangedDmg = 20;
	_lvl = 1;
	_name = "Farfalle";
	_armorDmgResist = 5;
	std::cout << "LOADING ";
	funnyScream();
	std::cout << ".initramfs..................DONE" << std::endl;
	std::cout << "LOADING " << _name << ".squashfs...........DONE" << std::endl;
	std::cout << "START UP SEQUENCE COMPLETE" << std::endl << std::endl;
}

FragTrap::FragTrap( std::string& name )
{
	_hp = 100;
	_hpMax = 100;
	_ep = 100;
	_epMax = 100;
	_meleeDmg = 30;
	_rangedDmg = 20;
	_lvl = 1;
	_name = name;
	_armorDmgResist = 5;
	std::cout << "LOADING ";
	funnyScream();
	std::cout << ".initramfs..................DONE" << std::endl;
	std::cout << "LOADING " << _name << ".squashfs...........DONE" << std::endl;
	std::cout << "START UP SEQUENCE COMPLETE" << std::endl << std::endl;
}

FragTrap::FragTrap( FragTrap const &cp )
{
	funnyScream();
	std::cout << " RUNNING JOB \"sudo cp -R / /mnt/NEW/\"..............";
	std::cout << "DONE" << std::endl;
	*this = cp;
}

FragTrap::~FragTrap( void )
{
	std::cout << "INITIATING ";
	funnyScream();
	std::cout << " SHUT DOWN SEQUENCE" << std::endl;
}

FragTrap& FragTrap::operator=( FragTrap const& beep )
{
	funnyScream();
	std::cout << " RUNNING JOB "
			  << "\"sudo dd of=/dev/sda if=/dev/sdf\"..............";
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


std::string _attacks[8] = {
	"swipes",
	"shoves",
	"spins",
	"cleaves",
	"splits",
	"crushes",
	"honks",
	"irritates"
};

void FragTrap::vaulthunter_dot_exe( const std::string& target )
{
	if (!_hp) {
		funnyScream();
		std::cout << " [" << _name << "] IS DED" << std::endl;
	} else {
		if (_ep >= 25) {
			funnyScream();
			std::cout << " [" << _name << "] ("
					  << _attacks[rand()%8] << ") {"
					  << target << "}" << std::endl;
			_ep -= 25;
		} else {
			funnyScream();
			std::cout << " [" << _name << "] is too tired" << std::endl;
		}
	}
}

void FragTrap::funnyScream( void ) const { std::cout << "FR4G-TP"; }
