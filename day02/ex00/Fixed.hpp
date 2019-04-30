#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

public:
	Fixed( void );
	Fixed( Fixed const & );
	~Fixed( void );
	Fixed& operator=( Fixed const& );

	int getRawBits( void ) const;
	void setRawBits( int const raw );

private:
	int _i;
	static const int _f = 8;

};

#endif /* FIXED_HPP */
