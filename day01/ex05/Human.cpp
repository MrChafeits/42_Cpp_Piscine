#include <string>
#include "Human.hpp"

Human::Human( void ) { }

Human::Human( Human const &cp ) { *this = cp; }

Human::~Human( void ) { }

Human& Human::operator=( Human const& ) { return *this; }

std::string Human::identify( void ) const { return this->_brain.identify(); }

const Brain& Human::getBrain( void ) const { return this->_brain; }
