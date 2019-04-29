#include "PhoneBook.hpp"

static void usage( void )
{
	std::cout << "CLI Phone Book" << std::endl;
	std::cout << "Standard Commands:" << std::endl;
	std::cout << " ADD" << std::endl;
	std::cout << " SEARCH" << std::endl;
	std::cout << " EXIT" << std::endl << std::endl;
}

int main( void )
{
	Phonebook bookCont;
	std::string ln;

	usage();
	while (1) {
		std::cout << "phonebook$ ";
		if (!std::getline(std::cin, ln)) break;
		bookCont.parse_input(ln);
	}
	return 0;
}
