#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap( void )
{
	_hp = 60;
	_hpMax = 60;
	_ep = 120;
	_epMax = 120;
	_meleeDmg = 60;
	_rangedDmg = 5;
	_lvl = 1;
	_name = "Farfalle";
	_armorDmgResist = 0;
	std::cout << "LOADING ";
	funnyScream();
	std::cout << ".initramfs..................DONE" << std::endl;
	std::cout << "LOADING " << _name << ".squashfs...........DONE" << std::endl;
	std::cout << "START UP SEQUENCE COMPLETE" << std::endl << std::endl;
}

NinjaTrap::NinjaTrap( std::string& name )
{
	_hp = 60;
	_hpMax = 60;
	_ep = 120;
	_epMax = 120;
	_meleeDmg = 60;
	_rangedDmg = 5;
	_lvl = 1;
	_name = name;
	_armorDmgResist = 0;
	std::cout << "LOADING ";
	funnyScream();
	std::cout << ".initramfs..................DONE" << std::endl;
	std::cout << "LOADING " << _name << ".squashfs...........DONE" << std::endl;
	std::cout << "START UP SEQUENCE COMPLETE" << std::endl << std::endl;
}

NinjaTrap::NinjaTrap( NinjaTrap const &cp )
{
	funnyScream();
	std::cout << " RUNNING JOB \"sudo cp -R / /mnt/NEW/\"..............";
	std::cout << "DONE" << std::endl;
	*this = cp;
}

NinjaTrap::~NinjaTrap( void )
{
	std::cout << "INITIATING ";
	funnyScream();
	std::cout << " SHUT DOWN SEQUENCE" << std::endl;
}

NinjaTrap& NinjaTrap::operator=( NinjaTrap const& beep )
{
	funnyScream();
	std::cout << " RUNNING JOB "
			  << "\"sudo dd of=/dev/sda if=/dev/sdn\"..............";
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

void NinjaTrap::ninjaShoebox( ClapTrap& c )
{
	if (!_hp) {
		funnyScream();
		std::cout << " [" << _name << "] IS DED" << std::endl;
	} else {
		if (_ep >= 25) {
			funnyScream();
			std::cout << " [" << _name << "] "
					  << "yeets {" << c.getName() << "}" << std::endl;
			_ep -= 25;
		} else {
			funnyScream();
			std::cout << " [" << _name << "] is too tired" << std::endl;
		}
	}
}

void NinjaTrap::ninjaShoebox( ScavTrap& c )
{
	if (!_hp) {
		funnyScream();
		std::cout << " [" << _name << "] IS DED" << std::endl;
	} else {
		if (_ep >= 25) {
			funnyScream();
			std::cout << " [" << _name << "] "
					  << "roflstomps {" << c.getName() << "}" << std::endl;
			_ep -= 25;
		} else {
			funnyScream();
			std::cout << " [" << _name << "] is too tired" << std::endl;
		}
	}
}

void NinjaTrap::ninjaShoebox( FragTrap& c )
{
	if (!_hp) {
		funnyScream();
		std::cout << " [" << _name << "] IS DED" << std::endl;
	} else {
		if (_ep >= 25) {
			funnyScream();
			std::cout << " [" << _name << "] "
					  << "fumbles {" << c.getName() << "}" << std::endl;
			_ep -= 25;
		} else {
			funnyScream();
			std::cout << " [" << _name << "] is too tired" << std::endl;
		}
	}
}

void NinjaTrap::ninjaShoebox( NinjaTrap& c )
{
	if (!_hp) {
		funnyScream();
		std::cout << " [" << _name << "] IS DED" << std::endl;
	} else {
		if (_ep >= 25) {
			funnyScream();
			std::cout << " [" << _name << "] "
					  << "chucks {" << c.getName() << "}" << std::endl;
			_ep -= 25;
		} else {
			funnyScream();
			std::cout << " [" << _name << "] is too tired" << std::endl;
		}
	}
}

void NinjaTrap::funnyScream( void ) const { std::cout << "N1NJ4-TP"; }
