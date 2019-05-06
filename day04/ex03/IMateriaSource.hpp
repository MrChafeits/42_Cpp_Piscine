#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>
#include "AMateria.hpp"

class IMateriaSource {

public:
	virtual ~IMateriaSource( void ) {}
	virtual void learnMateria( AMateria* ) = 0;
	virtual AMateria* createMateria( std::string const& ) = 0;

private:

};

#endif /* IMATERIASOURCE_HPP */
