#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {

public:
	Weapon( void );
	Weapon( std::string );
	Weapon( Weapon const & );
	~Weapon( void );
	Weapon& operator=( Weapon const& );

	const std::string& getType( void ) const;
	void setType( std::string );
	
private:
	std::string _type;

};

#endif /* WEAPON_HPP */
