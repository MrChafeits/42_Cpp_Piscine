#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <string>

class Enemy {

public:
	Enemy( void );
	Enemy( int , std::string const& );
	Enemy( Enemy const & );

	virtual ~Enemy( void );

	Enemy& operator=( Enemy const& );

	std::string const& getType( void ) const;
	int getHp( void ) const;

	virtual void takeDamage( int );

protected:
	virtual void onDeath( void ) const;

	int _hp;
	std::string const& _type;

private:
	static std::string _dtype;

};

#endif /* ENEMY_HPP */
