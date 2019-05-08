#include "span.hpp"

Span::Span( unsigned s ) throw(Span::BadSizeException): _size(s) {
	if (_size == 0 || _size >= 1048576)
		throw Span::BadSizeException();
	std::vector<int> _v(_size);
}

Span::Span( Span const &cp ) { *this = cp; }

Span::~Span( void ) { }

Span& Span::operator=( Span const& rhs ) {
	if (this != &rhs) {
		_size = rhs._size;
		std::vector<int> _v(_size);
		for (unsigned long i=0; i < _size; i++) _v.push_back(rhs._v[i]);
	}
	return *this;
}

void Span::addNumber( int n ) throw(Span::BadSizeException) {
	if (_v.size() >= _size)
		throw Span::BadSizeException();
	_v.push_back(n);
}

void Span::addNumber( int a, int b ) throw(Span::BadSizeException) {
	try { if (a > b) { a^=b; b^=a; a^=b; } for (; a <= b; a++) addNumber(a);
	} catch (Span::BadSizeException) { throw Span::BadSizeException(); }
}

int Span::shortestSpan( void ) throw(Span::BadSizeException) {
	if (_v.size() < 2) throw Span::BadSizeException();
	int d=INT_MAX;
	std::sort(_v.begin(), _v.end());
	std::vector<int>::iterator i = _v.begin(), j = _v.end();
	for (++j; j < _v.end() && d > 0; i++,j++) d = std::min(d, *j - *i);
	return d;
}

int Span::longestSpan( void ) throw(Span::BadSizeException) {
	if (_v.size() < 2) throw Span::BadSizeException();
	return *std::max_element(std::begin(_v), std::end(_v))-
		   *std::min_element(std::begin(_v), std::end(_v));
}
Span::BadSizeException::BadSizeException( void ) { }
Span::BadSizeException::BadSizeException( BadSizeException const &cp ) { *this = cp; }
Span::BadSizeException::~BadSizeException( void ) throw() { }
Span::BadSizeException& Span::BadSizeException::operator=( BadSizeException const& ) { return *this; }
const char	*Span::BadSizeException::what( void ) const throw() {
	return "Bad size";
}
