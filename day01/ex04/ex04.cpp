#include <iostream>
#include <string>

int main( void )
{
	std::string msg = "HI THIS IS BRAIN";
	std::string *ptr = &msg;
	std::string &ref = msg;

	std::cout << "std::string *ptr = \"" << *ptr << "\"" << std::endl;
	std::cout << "std::string &ref = \"" << ref << "\"" << std::endl;
	return 0;
}
