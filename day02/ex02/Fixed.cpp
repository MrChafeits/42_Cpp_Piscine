#include "Fixed.hpp"

const int Fixed::_fbits = 8;
//                       42.42;
// 000000000000000000010000.10010010
Fixed::Fixed( void ): _i(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed( const int i ): _i(i<<_fbits) { std::cout << "Int constructor called" << std::endl; }

Fixed::Fixed( const float f )
{
	std::cout << "Float constructor called" << std::endl;
	_i = std::roundf(f * (1 << _fbits));
}

Fixed::Fixed( const Fixed& cp )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cp;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=( const Fixed& as )
{ 
	std::cout << "Assignation operator called" << std::endl;
	_i = as.getRawBits();
	return *this;
}

std::ostream& operator<<( std::ostream& os, const Fixed& fi )
{
	os << fi.toFloat();
	return os;
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

float Fixed::toFloat( void ) const
{
	return _i / static_cast<float>(1 << _fbits);;
}

int Fixed::toInt( void ) const
{
	// int ret;
	// std::printf("(%d)",_i);//(_i ^ ((1<<_fbits)-1)));
	// if (_i ^ ((1<<_fbits)-1)) {
	// 	ret = _i;
	// } else {
	// 	ret = (_i >> _fbits);
	// }
	return _i >> _fbits;
}

bool Fixed::operator>( const Fixed& fi ) const { return this->toFloat() > fi.toFloat(); }

bool Fixed::operator<( const Fixed& fi ) const { return this->toFloat() < fi.toFloat(); }

bool Fixed::operator>=( const Fixed& fi ) const { return this->toFloat() >= fi.toFloat(); }

bool Fixed::operator<=( const Fixed& fi ) const { return this->toFloat() <= fi.toFloat(); }

bool Fixed::operator==( const Fixed& fi ) const { return this->toFloat() == fi.toFloat(); }

bool Fixed::operator!=( const Fixed& fi ) const { return this->toFloat() != fi.toFloat(); }

Fixed Fixed::operator+( const Fixed& fi ) const { return toFloat() + fi.toFloat(); }

Fixed Fixed::operator-( const Fixed& fi ) const { return toFloat() - fi.toFloat(); }

Fixed Fixed::operator*( const Fixed& fi ) const { return toFloat() * fi.toFloat(); }

Fixed Fixed::operator/( const Fixed& fi ) const { return toFloat() / fi.toFloat(); }

Fixed& Fixed::operator++( void ) { _i++; return *this; }

Fixed& Fixed::operator--( void ) { _i--; return *this; }

Fixed& Fixed::operator++( int ) { _i++; return *this; }

Fixed& Fixed::operator--( int ) { _i--; return *this; }

Fixed& Fixed::min( Fixed& lh, Fixed& rh ) { return lh < rh ? lh : rh; }

const Fixed& Fixed::min( const Fixed& lh, const Fixed& rh ) { return lh < rh ? lh : rh; }

Fixed& Fixed::max( Fixed& lh, Fixed& rh ) { return lh > rh ? lh : rh; }

const Fixed& Fixed::max( const Fixed& lh, const Fixed& rh ) { return lh > rh ? lh : rh; }
