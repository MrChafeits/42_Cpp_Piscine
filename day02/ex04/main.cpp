#include <istream>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include "Fixed.hpp"
static const unsigned char _valid_chr[256] = {
	['%'] = 1, ['('] = 2, [')'] = 3, ['*'] = 1,
	['-'] = 1, ['/'] = 1, ['0'] = 1, ['1'] = 1,
	['2'] = 1, ['3'] = 1, ['4'] = 1, ['5'] = 1,
	['6'] = 1, ['7'] = 1, ['8'] = 1, ['9'] = 1,
	['<'] = 1, ['='] = 1, ['>'] = 1,
};
int parse( char *argv)
{
	std::stringstream expr;
	std::string s(argv);
	int ret=0,b1,b2,b3,i;
	Fixed a, b;

	for (i=b1=b2=0; s[i] && !ret; i++) {
		switch (_valid_chr[static_cast<int>(s[i])]) {
		case 1: break;
		case 2: b1++; break;
		case 3: b2++; break;
		default:
			std::cout << "Error: illegal character -- \'"
					  << s[i] << "\'" << std::endl;
			ret=1;
			break;
		}
	}
	if (b1 != b2) {
		std::cout << "Error: imbalanced parenthesis, \'(\'[" << b1 << "] "
				  << "!= \')\'[" << b2 << "]" << std::endl;
		ret=1;
	} else {
		if (!ret) { //TODO
			for (i=0,b3=b1+b2; i < b3; i++) {
				if (!(b1 = s.rfind("(", b1)) || b1 == static_cast<long>(std::string::npos))
					exit(-1);
			}
		}
	}
	return ret;
}

int main( int argc, char *argv[] )
{
	int ret=0;

	switch (argc) {
	case 1:
		std::cout << "Error: empty expression" << std::endl;
		std::cout << "Usage: ./" << *argv << " [ expr ]" << std::endl;
		ret = 1; break;
	case 2:
		ret = parse(argv[1]);
		break;
	default:
		std::cout << "Error: too many expressions" << std::endl;
		ret = 2;
		break;
	}
	return ret;
}
