#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ): _hp(100), _hpMax(100),
							_ep(50), _epMax(50),
							_lvl(1), _name("Regular Ricardo"),
							_meleeDmg(20), _rangedDmg(15),
							_armorDmgResist(3) 
{
	std::cout << "INITIATING START UP SEQUENCE" << std::endl;
	std::cout << "LOADING SC4V_TP.initramfs..................DONE" << std::endl;
	std::cout << "LOADING " << _name << ".squashfs...........DONE" << std::endl;
	std::cout << "START UP SEQUENCE COMPLETE" << std::endl;
}

ScavTrap::ScavTrap( std::string& name ): _hp(100), _hpMax(100),
										 _ep(100), _epMax(100),
										 _lvl(1), _name(name),
										 _meleeDmg(30), _rangedDmg(20),
										 _armorDmgResist(5)
{
	std::cout << "INITIATING START UP SEQUENCE" << std::endl;
	std::cout << "LOADING SC4V_TP.initramfs..................DONE" << std::endl;
	std::cout << "LOADING " << _name << ".squashfs...........DONE" << std::endl;
	std::cout << "START UP SEQUENCE COMPLETE" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &cp )
{
	std::cout << "RUNNING JOB \"sudo cp -R / /mnt/NEW/\"..............";
	std::cout << "DONE" << std::endl;
	*this = cp;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "INITIATING SHUT DOWN SEQUENCE" << std::endl;
	std::cout << "STOPPING ALL JOBS..........................DONE" << std::endl;
	std::cout << "WIPING VOLATILE MEMORY.....................DONE" << std::endl;
	std::cout << "GOODBYE" << std::endl << std::endl;
}

ScavTrap& ScavTrap::operator=( ScavTrap const& beep )
{
	std::cout << "RUNNING JOB \"sudo dd of=/dev/sda if=/dev/sdc\"..............";
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

void ScavTrap::rangedAttack( const std::string& target ) const
{
	if (!_hp) {
		std::cout << "SC4V-TP [" << _name << "] IS DED" << std::endl;
	} else {
		std::cout << "SC4V-TP [" << _name
				  << "] attacks {" << target
				  << "} at range, causing <" << _rangedDmg
				  << "> points of damage!" << std::endl;
	}
}

void ScavTrap::meleeAttack( const std::string& target ) const
{
	if (!_hp) {
		std::cout << "SC4V-TP [" << _name << "] IS DED" << std::endl;
	} else {
		std::cout << "SC4V-TP [" << _name
				  << "] attacks {" << target
				  << "} up close, causing <" << _meleeDmg
				  << "> points of damage!" << std::endl;
	}
}

void ScavTrap::takeDamage( unsigned dmg )
{
	if (!_hp) {
		std::cout << "SC4V-TP [" << _name << "] IS DED" << std::endl;
	} else {
		unsigned tmp;
		double edmg(dmg), res(_armorDmgResist);
		res = 1.0 - (res / 100);
		tmp = edmg * res;
		if (_hp - tmp <= 0 || tmp >= _hp) {
			std::cout << "SC4V-TP [" << _name << "] got hit, receiving <"
					  << tmp << "> points of damage, killing them instantly."
					  << std::endl;
			setHp(0);
		} else {
			std::cout << "SC4V-TP [" << _name << "] got hit, receiving <"
					  << tmp << "> points of damage!" << std::endl;
			setHp(_hp - tmp);
		}
	}
}

void ScavTrap::beRepaired( unsigned dmg )
{
	if (!_hp) {
		_hp = _hp+dmg > _hpMax ? _hpMax : _hp+dmg;
		std::cout << "SC4V-TP [" << _name << "] is repaired for <" << dmg
				  << ">, yoinking them back to this meritless mortal coil"
				  << " with a mild <" << _hp << "> HP!"
				  << std::endl;
	} else {
		_hp = _hp+dmg > _hpMax ? _hpMax : _hp+dmg;
		std::cout << "SC4V-TP [" << _name << "] is repaired for <" << dmg
				  << "> giving them <" << _hp << "> HP." << std::endl;
	}
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
		std::cout << "SC4V-TP [" << _name << "] IS DED" << std::endl;
	} else {
		if (_ep >= 25) {
			std::cout << "SC4V-TP [" << _name
					  << "] challenges newcomer {" << target
					  << "}" << _challenges[rand()%8] << std::endl;
			_ep -= 25;
		} else {
			std::cout << "SC4V-TP [" << _name << "] is too tired" << std::endl;
		}
	}
}

// Getters
unsigned ScavTrap::getHp( void ) const { return _hp; }
unsigned ScavTrap::getHpMax( void ) const { return _hpMax; }
unsigned ScavTrap::getEp( void ) const { return _ep; }
unsigned ScavTrap::getEpMax( void ) const { return _epMax; }
unsigned ScavTrap::getLvl( void ) const { return _lvl; }
const std::string& ScavTrap::getName( void ) const { return _name; }
unsigned ScavTrap::getMeleeDmg( void ) const { return _meleeDmg; }
unsigned ScavTrap::getRangedDmg( void ) const { return _rangedDmg; }
unsigned ScavTrap::getArmorDmgResist( void ) const { return _armorDmgResist; }

// Setters
void ScavTrap::setHp( unsigned hp ) { _hp = hp; }
void ScavTrap::setHpMax( unsigned hp_max ) { _hpMax = hp_max; }
void ScavTrap::setEp( unsigned ep ) { _ep = ep; }
void ScavTrap::setEpMax( unsigned ep_max ) { _epMax = ep_max; }
void ScavTrap::setLvl( unsigned lvl ) { _lvl = lvl; }
void ScavTrap::setName( std::string& name ) { _name = name; }
void ScavTrap::setMeleeDmg( unsigned dmg ) { _meleeDmg = dmg; }
void ScavTrap::setRangedDmg( unsigned dmg ) { _rangedDmg = dmg; }
void ScavTrap::setArmorDmgResist( unsigned dmg ) { _armorDmgResist = dmg; }
