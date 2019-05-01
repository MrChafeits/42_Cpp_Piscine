#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << (a < b) << std::endl;
	std::cout << (a > b) << std::endl;
	std::cout << (a <= b) << std::endl;
	std::cout << (a >= b) << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << (a != b) << std::endl;

	std::cout << (a + b) << std::endl;
	std::cout << (a - b) << std::endl;
	std::cout << (a * b) << std::endl;
	std::cout << (a / b) << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::min(a,b) << std::endl;
	std::cout << Fixed::max(a,b) << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;

	return 0;
}
