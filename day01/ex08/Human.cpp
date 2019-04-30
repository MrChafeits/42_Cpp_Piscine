#include <iostream>
#include <string>
#include "Human.hpp"

void Human::meleeAttack( std::string const &target )
{
	std::cout << "Human whacks ["
			  << target
			  << "] with a SSBM disc case "
			  << "in a ludicrous display of (melee) prowess"
			  << std::endl;
}

void Human::rangedAttack( std::string const &target )
{
	std::cout << "Human hucks a SSBM disc from a (range) at ["
			  << target << "]"
			  << std::endl;
}

void Human::intimidatingShout( std::string const &target )
{
	std::cout << "Human performs an (intimidating shout) "
			  << "in the general direction of ["
			  << target << "]"
			  << std::endl;
}

void Human::action( std::string const & action_name, std::string const & target )
{
	std::string whomst[3] = {"melee", "ranged", "intimidate"};
	void (Human::*act[3])( const std::string& ) = {&Human::meleeAttack,
												   &Human::rangedAttack,
												   &Human::intimidatingShout};
	for (int i = 0; i < 3; i++)
		if (action_name == whomst[i])
			(this->*act[i])(target);
}
