#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <string>

typedef struct s_fuck t_fuck;

class Human {

public:
	Human( void );
	~Human( void );
	void action( std::string const &action_name, std::string const &target );
	void (Human::*act[])( std::string const &target );
	void stma( std::string const& );
	void stmr( std::string const& );
	void stmi( std::string const& );

private:
	void meleeAttack( std::string const &target );
	void rangedAttack( std::string const &target );
	void intimidatingShout( std::string const &target );
	static t_fuck fun[3];
};

struct s_fuck {
	void (Human::*f)( std::string const& );
	std::string n;
};

#endif /* HUMAN_HPP */
