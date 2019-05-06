#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria {

public:
	AMateria( void );
	AMateria( std::string const& );
	AMateria( AMateria const & );
	virtual ~AMateria( void );
	AMateria& operator=( AMateria const& );

	std::string const& getType( void ) const; //Returns materia's type
	unsigned getXp( void ) const; //Returns materia's xp

	virtual AMateria* clone( void ) const = 0;
	virtual void use( ICharacter& );

private:
	std::string const& _type;
	unsigned _xp;

};

#endif /* AMATERIA_HPP */
