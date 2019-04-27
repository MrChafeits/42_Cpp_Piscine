#include "PhoneBook.hpp"

static void usage( void )
{
	std::cout << "Book of Phone" << std::endl;
	std::cout << "Standard Commands:" << std::endl;
	std::cout << "ADD" << std::endl;
	std::cout << "SEARCH" << std::endl;
	std::cout << "EXIT" << std::endl << std::endl;
}

int main( void )
{
	Phonebook bookConk;

	usage();
	std::cout << "phonebook$ ";
	for (std::string ln; std::getline(std::cin, ln); ln.clear()) {
		bookConk.parse_input(ln);
		if (ln.length())
			std::cout << "phonebook$ ";
	}
}
