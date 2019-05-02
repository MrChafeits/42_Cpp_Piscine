#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ): _hp(0), _hpMax(0),
							_ep(0), _epMax(0),
							_lvl(0), _name("NULL"),
							_meleeDmg(0), _rangedDmg(0),
							_armorDmgResist(0) 
{
	std::cout << "INITIATING START UP SEQUENCE" << std::endl;
	std::cout << "LOADING "; funnyScream();
	std::cout << ".initramfs..................DONE" << std::endl;
	std::cout << "LOADING " << _name << ".squashfs...........DONE" << std::endl;
}

ClapTrap::ClapTrap( std::string& name ): _hp(0), _hpMax(0),
										 _ep(0), _epMax(0),
										 _lvl(0), _name(name),
										 _meleeDmg(0), _rangedDmg(0),
										 _armorDmgResist(0)
{
	std::cout << "INITIATING START UP SEQUENCE" << std::endl;
	std::cout << "LOADING "; funnyScream();
	std::cout << ".initramfs..................DONE" << std::endl;
	std::cout << "LOADING " << _name << ".squashfs...........DONE" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &cp )
{
	funnyScream();
	std::cout << " RUNNING JOB \"sudo cp -R / /mnt/NEW/\"..............";
	std::cout << "DONE" << std::endl;
	*this = cp;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "LOADING "; funnyScream();
	std::cout << " SHUT DOWN SEQUENCE" << std::endl;
	std::cout << "STOPPING ALL JOBS..........................DONE" << std::endl;
	std::cout << "WIPING VOLATILE MEMORY.....................DONE" << std::endl;
	std::cout << "GOODBYE" << std::endl << std::endl;
}

ClapTrap& ClapTrap::operator=( ClapTrap const& beep )
{
	funnyScream();
	std::cout << " RUNNING JOB "
			  << "\"sudo dd of=/dev/sda if=/dev/sdc\"..............";
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

void ClapTrap::rangedAttack( const std::string& target ) const
{
	if (!_hp) {
		funnyScream();
		std::cout << " [" << _name << "] IS DED" << std::endl;
	} else {
		funnyScream();
		std::cout << " [" << _name
				  << "] attacks {" << target
				  << "} at range, causing <" << _rangedDmg
				  << "> points of damage!" << std::endl;
	}
}

void ClapTrap::meleeAttack( const std::string& target ) const
{
	if (!_hp) {
		funnyScream();
		std::cout << " [" << _name << "] IS DED" << std::endl;
	} else {
		funnyScream();
		std::cout << " [" << _name
				  << "] attacks {" << target
				  << "} up close, causing <" << _meleeDmg
				  << "> points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage( unsigned dmg )
{
	if (!_hp) {
		funnyScream();
		std::cout << " [" << _name << "] IS DED" << std::endl;
	} else {
		unsigned tmp;
		double edmg(dmg), res(_armorDmgResist);
		res = 1.0 - (res / 100);
		tmp = edmg * res;
		if (_hp - tmp <= 0 || tmp >= _hp) {
		funnyScream();
			std::cout << " [" << _name << "] got hit, receiving <"
					  << tmp << "> points of damage, killing them instantly."
					  << std::endl;
			setHp(0);
		} else {
		funnyScream();
			std::cout << " [" << _name << "] got hit, receiving <"
					  << tmp << "> points of damage!" << std::endl;
			setHp(_hp - tmp);
		}
	}
}

void ClapTrap::beRepaired( unsigned dmg )
{
	if (!_hp) {
		_hp = _hp+dmg > _hpMax ? _hpMax : _hp+dmg;
		funnyScream();
		std::cout << " [" << _name << "] is repaired for <" << dmg
				  << ">, yoinking them back to this meritless mortal coil"
				  << " with a mild <" << _hp << "> HP!"
				  << std::endl;
	} else {
		_hp = _hp+dmg > _hpMax ? _hpMax : _hp+dmg;
		funnyScream();
		std::cout << " [" << _name << "] is repaired for <" << dmg
				  << "> giving them <" << _hp << "> HP." << std::endl;
	}
}

void ClapTrap::funnyScream( void ) const { std::cout << "CL4P-TP"; }

// Getters
unsigned ClapTrap::getHp( void ) const { return _hp; }
unsigned ClapTrap::getHpMax( void ) const { return _hpMax; }
unsigned ClapTrap::getEp( void ) const { return _ep; }
unsigned ClapTrap::getEpMax( void ) const { return _epMax; }
unsigned ClapTrap::getLvl( void ) const { return _lvl; }
const std::string& ClapTrap::getName( void ) const { return _name; }
unsigned ClapTrap::getMeleeDmg( void ) const { return _meleeDmg; }
unsigned ClapTrap::getRangedDmg( void ) const { return _rangedDmg; }
unsigned ClapTrap::getArmorDmgResist( void ) const { return _armorDmgResist; }

// Setters
void ClapTrap::setHp( unsigned hp ) { _hp = hp; }
void ClapTrap::setHpMax( unsigned hp_max ) { _hpMax = hp_max; }
void ClapTrap::setEp( unsigned ep ) { _ep = ep; }
void ClapTrap::setEpMax( unsigned ep_max ) { _epMax = ep_max; }
void ClapTrap::setLvl( unsigned lvl ) { _lvl = lvl; }
void ClapTrap::setName( std::string& name ) { _name = name; }
void ClapTrap::setMeleeDmg( unsigned dmg ) { _meleeDmg = dmg; }
void ClapTrap::setRangedDmg( unsigned dmg ) { _rangedDmg = dmg; }
void ClapTrap::setArmorDmgResist( unsigned dmg ) { _armorDmgResist = dmg; }
