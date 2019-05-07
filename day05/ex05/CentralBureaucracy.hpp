#ifndef CENTRALBUREAUCRACY_HPP
#define CENTRALBUREAUCRACY_HPP

#include "OfficeBlock.hpp"

class CentralBureaucracy {

public:
	CentralBureaucracy( void );
	CentralBureaucracy( CentralBureaucracy const & );
	~CentralBureaucracy( void );
	CentralBureaucracy& operator=( CentralBureaucracy const& );

	void queueUp( std::string n );

private:
	OfficeBlock* _o;

};

#endif /* CENTRALBUREAUCRACY_HPP */
