#include "Ice.hpp"

Ice::Ice( void ) { }

Ice::Ice( Ice const &cp ) { *this = cp; }

Ice::~Ice( void ) { }

Ice& Ice::operator=( Ice const& ) { return *this; } // TODO: implement
