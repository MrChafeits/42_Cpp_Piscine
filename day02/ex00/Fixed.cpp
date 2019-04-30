#include "Fixed.hpp"

Fixed::Fixed( void ): _i(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed( Fixed const &cp )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cp;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=( Fixed const &ob )
{ 
	std::cout << "Assignation operator called" << std::endl;
	_i = ob.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_i;
}

void Fixed::setRawBits( const int raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_i = raw;
}
