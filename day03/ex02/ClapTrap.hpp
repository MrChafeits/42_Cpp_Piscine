#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {

public:
	ClapTrap( void );
	ClapTrap( std::string& );
	ClapTrap( const ClapTrap& );
	~ClapTrap( void );
	ClapTrap& operator=( const ClapTrap& );

	void rangedAttack( const std::string& ) const;
	void meleeAttack( const std::string& ) const;
	void takeDamage( unsigned );
	void beRepaired( unsigned );

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

	virtual void funnyScream( void ) const;

protected:
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

#endif /* CLAPTRAP_HPP */
