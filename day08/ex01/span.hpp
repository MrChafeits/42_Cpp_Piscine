#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class Span {

public:
	Span( unsigned ) throw(Span::BadSizeException);
	Span( Span const & );
	~Span( void );
	Span& operator=( Span const& );
	class BadSizeException : public std::exception {
	public:
		BadSizeException( void );
		BadSizeException( BadSizeException const& );
		~BadSizeException( void ) throw();
		BadSizeException& operator=( BadSizeException const& );
		virtual const char*	what() const throw();
	};
	void addNumber( int ) throw(Span::BadSizeException);
	void addNumber( int, int ) throw(Span::BadSizeException);
	int shortestSpan( void ) throw(Span::BadSizeException);
	int longestSpan( void ) throw(Span::BadSizeException);
	
private:
	unsigned _size;
	std::vector<int> _v;

};

#endif /* SPAN_HPP */
