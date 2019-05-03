#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>
#include <string>

class Victim {

public:
	Victim( void );
	Victim( std::string const& );
	Victim( Victim const & );

	~Victim( void );

	Victim& operator=( Victim const& );

	void getPolymorphed( void ) const;
	std::string const& getName( void ) const;
	void setName( std::string const& );

private:
	std::string _name;

};

std::ostream& operator<<( std::ostream&, Victim const& );

#endif /* VICTIM_HPP */
