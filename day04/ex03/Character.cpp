#include "Character.hpp"

Character::Character( void ) { }

Character::Character( Character const &cp ) { *this = cp; }

Character::~Character( void ) { }

Character& Character::operator=( Character const& ) { return *this; } // TODO: implement
