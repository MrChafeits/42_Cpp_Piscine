#include <iostream>
#include "Human.hpp"

int main(int ac, char **av)
{
	Human bob;
	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;

	if (ac > 1 && !std::strncmp(av[1], "leak", 5)) while(1);
	return 0;
}
