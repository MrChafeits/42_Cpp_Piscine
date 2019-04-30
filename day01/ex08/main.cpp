#include <string>
#include <iostream>
#include "Human.hpp"

int main( void )
{
	Human norman_biggio;
	std::string const a1 = "melee";
	std::string const a2 = "ranged";
	std::string const a3 = "intimidate";
	std::string const t1 = "Fox McCloud";
	std::string const t2 = "Ganondorf";
	std::string const t3 = "Waluigi";
	norman_biggio.action(a1, t1);
	norman_biggio.action(a2, t2);
	norman_biggio.action(a3, t3);
	return 0;
}
