#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {

public:
	Brain( void );
	Brain( bool );
	Brain( Brain const & );
	~Brain( void );
	Brain& operator=( Brain const& );

	std::string identify( void ) const;
	bool isSmort( void ) const;
	void setSmort( bool );

private:
	bool _smort;

};

#endif /* BRAIN_HPP */
