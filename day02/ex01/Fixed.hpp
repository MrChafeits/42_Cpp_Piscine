#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {

public:
	Fixed( void );
	Fixed( const int );
	Fixed( const float );
	Fixed( Fixed const & );
	~Fixed( void );

	Fixed& operator=( Fixed const& );

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

private:
	int _i;
	static const int _fbits;

};

std::ostream& operator<<( std::ostream&, Fixed const& );

#endif /* FIXED_HPP */
