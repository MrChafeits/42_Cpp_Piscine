#include "FragTrap.hpp"

FragTrap::FragTrap( void ): _hp(100), _hpMax(100),
							_ep(100), _epMax(100),
							_lvl(1), _name("Defaultio Donnatello"),
							_meleeDmg(30), _rangedDmg(20),
							_armorDmgResist(5) 
{
	std::cout << "INITIATING START UP SEQUENCE" << std::endl;
	std::cout << "LOADING FR4G_TP.initramfs..................DONE" << std::endl;
	std::cout << "LOADING " << _name << ".squashfs...........DONE" << std::endl;
	std::cout << "START UP SEQUENCE COMPLETE" << std::endl;
}

FragTrap::FragTrap( std::string& name ): _hp(100), _hpMax(100),
										 _ep(100), _epMax(100),
										 _lvl(1), _name(name),
										 _meleeDmg(30), _rangedDmg(20),
										 _armorDmgResist(5)
{
	std::cout << "INITIATING START UP SEQUENCE" << std::endl;
	std::cout << "LOADING FR4G_TP.initramfs..................DONE" << std::endl;
	std::cout << "LOADING " << _name << ".squashfs...........DONE" << std::endl;
	std::cout << "START UP SEQUENCE COMPLETE" << std::endl;
}

FragTrap::FragTrap( FragTrap const &cp )
{
	std::cout << "RUNNING JOB \"sudo cp -R / /mnt/NEW/\"..............";
	std::cout << "DONE" << std::endl;
	*this = cp;
}

FragTrap::~FragTrap( void )
{
	std::cout << "INITIATING SHUT DOWN SEQUENCE" << std::endl;
	std::cout << "STOPPING ALL JOBS..........................DONE" << std::endl;
	std::cout << "WIPING VOLATILE MEMORY.....................DONE" << std::endl;
	std::cout << "GOODBYE" << std::endl << std::endl;
}

FragTrap& FragTrap::operator=( FragTrap const& beep )
{
	std::cout << "RUNNING JOB \"sudo dd of=/dev/sda if=/dev/sdb\"..............";
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

void FragTrap::rangedAttack( const std::string& target ) const
{
	if (!_hp) {
		std::cout << "FR4G-TP [" << _name << "] IS DED" << std::endl;
	} else {
		std::cout << "FR4G-TP [" << _name
				  << "] attacks {" << target
				  << "} at range, causing <" << _rangedDmg
				  << "> points of damage!" << std::endl;
	}
}

void FragTrap::meleeAttack( const std::string& target ) const
{
	if (!_hp) {
		std::cout << "FR4G-TP [" << _name << "] IS DED" << std::endl;
	} else {
		std::cout << "FR4G-TP [" << _name
				  << "] attacks {" << target
				  << "} up close, causing <" << _meleeDmg
				  << "> points of damage!" << std::endl;
	}
}

void FragTrap::takeDamage( unsigned dmg )
{
	if (!_hp) {
		std::cout << "FR4G-TP [" << _name << "] IS DED" << std::endl;
	} else {
		unsigned tmp;
		double edmg(dmg), res(_armorDmgResist);
		res = 1.0 - (res / 100);
		tmp = edmg * res;
		if (_hp - tmp <= 0 || tmp >= _hp) {
			std::cout << "FR4G-TP [" << _name << "] got hit, receiving <"
					  << tmp << "> points of damage, killing them instantly."
					  << std::endl;
			setHp(0);
		} else {
			std::cout << "FR4G-TP [" << _name << "] got hit, receiving <"
					  << tmp << "> points of damage!" << std::endl;
			setHp(_hp - tmp);
		}
	}
}

void FragTrap::beRepaired( unsigned dmg )
{
	if (!_hp) {
		_hp = _hp+dmg > _hpMax ? _hpMax : _hp+dmg;
		std::cout << "FR4G-TP [" << _name << "] is repaired for <" << dmg
				  << ">, yoinking them back to this mediocre mortal coil with a"
				  << " meager <" << _hp << "> HP!"
				  << std::endl;
	} else {
		_hp = _hp+dmg > _hpMax ? _hpMax : _hp+dmg;
		std::cout << "FR4G-TP [" << _name << "] is repaired for <" << dmg
				  << "> giving them <" << _hp << "> HP." << std::endl;
	}
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
		std::cout << "FR4G-TP [" << _name << "] IS DED" << std::endl;
	} else {
		if (_ep >= 25) {
			std::cout << "FR4G-TP [" << _name << "] ("
					  << _attacks[rand()%8] << ") {"
					  << target << "}" << std::endl;
			_ep -= 25;
		} else {
			std::cout << "FR4G-TP [" << _name << "] is too tired" << std::endl;
		}
	}
}

// Getters
unsigned FragTrap::getHp( void ) const { return _hp; }
unsigned FragTrap::getHpMax( void ) const { return _hpMax; }
unsigned FragTrap::getEp( void ) const { return _ep; }
unsigned FragTrap::getEpMax( void ) const { return _epMax; }
unsigned FragTrap::getLvl( void ) const { return _lvl; }
const std::string& FragTrap::getName( void ) const { return _name; }
unsigned FragTrap::getMeleeDmg( void ) const { return _meleeDmg; }
unsigned FragTrap::getRangedDmg( void ) const { return _rangedDmg; }
unsigned FragTrap::getArmorDmgResist( void ) const { return _armorDmgResist; }

// Setters
void FragTrap::setHp( unsigned hp ) { _hp = hp; }
void FragTrap::setHpMax( unsigned hp_max ) { _hpMax = hp_max; }
void FragTrap::setEp( unsigned ep ) { _ep = ep; }
void FragTrap::setEpMax( unsigned ep_max ) { _epMax = ep_max; }
void FragTrap::setLvl( unsigned lvl ) { _lvl = lvl; }
void FragTrap::setName( std::string& name ) { _name = name; }
void FragTrap::setMeleeDmg( unsigned dmg ) { _meleeDmg = dmg; }
void FragTrap::setRangedDmg( unsigned dmg ) { _rangedDmg = dmg; }
void FragTrap::setArmorDmgResist( unsigned dmg ) { _armorDmgResist = dmg; }
