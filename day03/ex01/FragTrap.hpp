#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>

class FragTrap {

public:
	FragTrap( void );
	FragTrap( std::string& );
	FragTrap( const FragTrap& );
	~FragTrap( void );
	FragTrap& operator=( const FragTrap& );

	void rangedAttack( const std::string& ) const;
	void meleeAttack( const std::string& ) const;
	void takeDamage( unsigned );
	void beRepaired( unsigned );
	void vaulthunter_dot_exe( const std::string& );

	unsigned getHp( void ) const;
	unsigned getHpMax( void ) const;
	unsigned getEp( void ) const;
	unsigned getEpMax( void ) const;
	unsigned getLvl( void ) const;
	const std::string& getName( void ) const;
	unsigned getMeleeDmg( void ) const;
	unsigned getRangedDmg( void ) const;
	unsigned getArmorDmgResist( void ) const;

	void setHp( unsigned );
	void setHpMax( unsigned );
	void setEp( unsigned );
	void setEpMax( unsigned );
	void setLvl( unsigned );
	void setName( std::string& );
	void setMeleeDmg( unsigned );
	void setRangedDmg( unsigned );
	void setArmorDmgResist( unsigned );

private:
	unsigned _hp;
	unsigned _hpMax;
	unsigned _ep;
	unsigned _epMax;
	unsigned _lvl;
	std::string _name;
	unsigned _meleeDmg;
	unsigned _rangedDmg;
	unsigned _armorDmgResist;

};

#endif /* FRAGTRAP_HPP */
