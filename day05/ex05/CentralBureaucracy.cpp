#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy( void ) {
	_o = new OfficeBlock[20];
}

CentralBureaucracy::CentralBureaucracy( CentralBureaucracy const &cp ) { *this = cp; }

CentralBureaucracy::~CentralBureaucracy( void ) { }

CentralBureaucracy& CentralBureaucracy::operator=( CentralBureaucracy const& ) { return *this; } // TODO: implement
