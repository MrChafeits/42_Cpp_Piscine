#ifndef PONY_HPP
#define PONY_HPP

#include <string>

class Pony {

public:
	Pony( void );
	Pony( Pony const & );
	~Pony( void );
	Pony& operator=( Pony const& );

	void setName( std::string );
	void setAge( std::string );
	void setMane( std::string );
	void setCoat( std::string );

	std::string getAge( void ) const;
	std::string getCoat( void ) const;
	std::string getMane( void ) const;
	std::string getName( void ) const;

private:
	std::string _age;
	std::string _coat;
	std::string _mane;
	std::string _name;

};

#endif
