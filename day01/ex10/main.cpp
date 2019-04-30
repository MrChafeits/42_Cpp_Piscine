#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char **argv)
{
	int ret = 0;
	if (argc == 1) std::cout << std::cin.rdbuf();
	else {
		for (int i = 1; i < argc; i++) {
			std::string foil_nam(argv[i]);
			std::ifstream ifs(foil_nam);
			if (ifs) {
				std::cout << ifs.rdbuf();
			} else {
				std::cout << "cato9tails: Error: Unable to open "
						  << foil_nam
						  << std::endl;
			}
		}
	}
	return ret;
}
