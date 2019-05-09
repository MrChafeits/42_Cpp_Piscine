#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <iostream>
#include <stdexcept>
#include <vector>

class Token {

public:
	Token( void );
	Token( Token const & );
	~Token( void );
	Token& operator=( Token const& );

private:

};

#endif /* TOKEN_HPP */
