#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {

public:
	Fixed( void );
	Fixed( const int );
	Fixed( const float );
	Fixed( const Fixed& );
	~Fixed( void );

	Fixed& operator=( const Fixed& );

	bool operator>( const Fixed& ) const;
	bool operator<( const Fixed& ) const;
	bool operator>=( const Fixed& ) const;
	bool operator<=( const Fixed& ) const;
	bool operator==( const Fixed& ) const;
	bool operator!=( const Fixed& ) const;

	Fixed operator+( const Fixed& ) const;
	Fixed operator-( const Fixed& ) const;
	Fixed operator*( const Fixed& ) const;
	Fixed operator/( const Fixed& ) const;

	Fixed& operator++( void );
	Fixed& operator--( void );
	Fixed& operator++( int );
	Fixed& operator--( int );

	static Fixed& min( Fixed&, Fixed& );
	static const Fixed& min( const Fixed&, const Fixed& );
	static Fixed& max( Fixed&, Fixed& );
	static const Fixed& max( const Fixed&, const Fixed& );

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

private:
	int _i;
	static const int _fbits;

};

std::ostream& operator<<( std::ostream&, const Fixed& );


#endif /* FIXED_HPP */
