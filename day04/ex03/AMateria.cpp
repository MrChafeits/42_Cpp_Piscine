#include "AMateria.hpp"

AMateria::AMateria( void ) { }

AMateria::AMateria( AMateria const &cp ) { *this = cp; }

AMateria::~AMateria( void ) { }

AMateria& AMateria::operator=( AMateria const& ) { return *this; } // TODO: implement
