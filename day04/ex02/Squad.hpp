#ifndef SQUAD_HPP
#define SQUAD_HPP

#include <iostream>
#include <string>
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

#define MAXSIZ (8192)

class Squad: public ISquad {

public:
	Squad( void );
	Squad( Squad const & );
	~Squad( void );
	Squad& operator=( Squad const& );

	int getCount( void ) const;
	ISpaceMarine* getUnit( int ) const;
	int push( ISpaceMarine* );

private:
	int _total;
	ISpaceMarine* _arr[MAXSIZ];

};

#endif /* SQUAD_HPP */
