#include <iostream>
#include "Human.hpp"

Human::Human( void )
{
	this->fun[3] = {{ &Human::meleeAttack, "melee" },
					{ &Human::rangedAttack, "ranged" },
					{ &Human::intimidatingShout, "intimidate" }};
}

Human::~Human( void ) { }

void Human::meleeAttack( std::string const &target )
{
	std::cout << "Human whacks " << target << " with a SSBM disc case" << std::endl;
}
void Human::stma( std::string const &t ) { this->meleeAttack(t); }
void Human::stmr( std::string const &t ) { this->rangedAttack(t); }
void Human::stmi( std::string const &t ) { this->intimidatingShout(t); }
void Human::rangedAttack( std::string const &target )
{
	std::cout << "Human hucks a SSBM disc at " << target << std::endl;
}

void Human::intimidatingShout( std::string const &target )
{
	std::cout << " intimidating shout " << target << std::endl;
}

void Human::action( std::string const &an, std::string const &t )
{
	void (Human::*act[3])( std::string const& ) = {&Human::stma,
												   &Human::stmr,
												   &Human::stmi};
	for (int i = 0; i < 3; i++)
		if (an == fun[i].n)
			*act[i](t);
}
