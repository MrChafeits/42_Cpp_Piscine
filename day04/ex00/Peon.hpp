#ifndef PEON_HPP
#define PEON_HPP

#include <iostream>
#include <string>
#include "Victim.hpp"

class Peon : public Victim {

public:
	Peon( void );
	Peon( std::string const& );
	Peon( Peon const & );

	~Peon( void );

	Peon& operator=( Peon const& );

	virtual void getPolymorphed( void ) const;
	std::string const& getName( void ) const;
	void setName( std::string const& );

private:
	std::string _name;

};

#endif /* PEON_HPP */
