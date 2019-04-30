#include <iostream>
#include "Human.hpp"

int main(int ac, char *av[])
{
	Human norman_biggio;
	std::string const a1 = "melee";
	std::string const a2 = "ranged";
	std::string const a3 = "intimidate";
	std::string const t1 = "Fox McCloud";
	std::string const t2 = "Ganondord";
	std::string const t3 = "Waluigi";
	norman_biggio.action(a1, t1);
	norman_biggio.action(a2, t2);
	norman_biggio.action(a3, t3);
	if (ac > 1 && !std::strncmp(av[1], "leak", 5)) while(1);
	return 0;
}
