#include <iostream>
#include "Array.hpp"

int				main(void)
{
	register unsigned i;
	srand(time(0));
	int	n = rand() % 10;
	Array<int> test(n);

	std::cout << "Array size: " << test.size() << std::endl;

	try {
		for (i=0;i<test.size();i++) test[i] = rand() % 100;
		for (i=0;i<=test.size();i++) std::cout << "Array["
											   << i
											   << "] Content: "
											   << test[i]
											   << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
