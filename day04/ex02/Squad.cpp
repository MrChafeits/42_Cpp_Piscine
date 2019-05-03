#include "Squad.hpp"

Squad::Squad( void ) {
	_total = 0;
}

Squad::Squad( Squad const &cp ) { *this = cp; }

Squad::~Squad( void ) { for (int i=0;i<_total;i++) delete _arr[i]; }

Squad& Squad::operator=( Squad const& ) { return *this; } // TODO: implement

int Squad::getCount( void ) const { return _total; }

ISpaceMarine* Squad::getUnit( int n ) const {
	if (n < _total && n >= 0 && n < MAXSIZ) return _arr[n];
	return nullptr;
}

int Squad::push( ISpaceMarine* m ) {
	if (_total >= MAXSIZ) return _total;
	_arr[_total++] = m;
	return _total;
}
