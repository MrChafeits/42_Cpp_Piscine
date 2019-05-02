#include "SuperTrap.hpp"

SuperTrap::SuperTrap( void )
{
	_hp = 100;
	_hpMax = 100;
	_ep = 120;
	_epMax = 120;
	_meleeDmg = 60;
	_rangedDmg = 20;
	_lvl = 1;
	_name = "Shifto";
	_armorDmgResist = 5;
	std::cout << "LOADING ";
	funnyScream();
	std::cout << ".initramfs..................DONE" << std::endl;
	std::cout << "LOADING " << _name << ".squashfs...........DONE" << std::endl;
	std::cout << "START UP SEQUENCE COMPLETE" << std::endl << std::endl;
}

SuperTrap::SuperTrap( std::string& name )
{
	_hp = 100;
	_hpMax = 100;
	_ep = 120;
	_epMax = 120;
	_meleeDmg = 60;
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

SuperTrap::SuperTrap( SuperTrap const &cp )
{
	funnyScream();
	std::cout << " RUNNING JOB \"sudo cp -R / /mnt/NEW/\"..............";
	std::cout << "DONE" << std::endl;
	*this = cp;
}

SuperTrap::~SuperTrap( void )
{
	std::cout << "INITIATING ";
	funnyScream();
	std::cout << " SHUT DOWN SEQUENCE" << std::endl;
}

SuperTrap& SuperTrap::operator=( SuperTrap const& beep )
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

void SuperTrap::funnyScream( void ) const { std::cout << "SUP3R-TP"; }
