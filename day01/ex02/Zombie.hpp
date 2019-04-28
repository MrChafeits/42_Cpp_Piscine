#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <random>
#include <string>

class Zombie {

public:
	Zombie( void );
	Zombie( std::string n );
	Zombie( std::string n, std::string t );
	~Zombie( void );

	void announce( void ) const;

	void setName( std::string );
	void setType( std::string );

	std::string getName( void ) const;
	std::string getType( void ) const;

private:
	std::string _name;
	std::string _type;

};

#endif
