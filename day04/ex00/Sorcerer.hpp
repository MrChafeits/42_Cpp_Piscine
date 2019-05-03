#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <iostream>
#include <string>
#include "Victim.hpp"
#include "Peon.hpp"

class Sorcerer {

public:
	Sorcerer( void );
	Sorcerer( std::string const&, std::string const& );
	Sorcerer( Sorcerer const & );
	~Sorcerer( void );
	Sorcerer& operator=( Sorcerer const& );

	std::string const& getName( void ) const;
	std::string const& getTitle( void ) const;
	void setName( std::string const& );
	void setTitle( std::string const& );
	void polymorph( Victim const& ) const;
	void polymorph( Peon const& ) const;

private:
	std::string _name;
	std::string _title;

};

std::ostream& operator<<( std::ostream&, Sorcerer const& );

#endif /* SORCERER_HPP */
