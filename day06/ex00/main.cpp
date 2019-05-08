#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

// static_cast<> - similar to c-style cast
// dynamic_cast<> - evaluated at runtime
// reinterpret_cast<> - bit smoosh with no conversion
// const_cast<> - fuckoff const n lemme convert

int main(int argc, char* argv[]) {
	register int i;
	std::string s;
	char c=0;
	int n=0;
	float f=0;
	double d=0;

	if (argc > 1) {
		for (i=0; i<argc; i++) {
			s = std::string(argv[i]);
			if (s.size() == 1 && !isdigit(s[0])) {
				c = static_cast<char>(s[0]);
				n = static_cast<int>(c);
				f = static_cast<float>(c);
				d = static_cast<double>(c);
			} else if (!s.find('.')) {
				n = atoi(s.c_str());
				c = static_cast<char>(n);
				f = static_cast<float>(n);
				d = static_cast<double>(n);
			} else {
				if (s.find('f')) {
					f = atof(s.c_str());
					c = static_cast<char>(f);
					n = static_cast<int>(f);
					d = static_cast<double>(f);
				} else {
					d = strtod(s.c_str(), NULL);
					c = static_cast<char>(d);
					n = static_cast<int>(d);
					f = static_cast<float>(d);
				}
			}
		}
		if (isnan(d) || isinf(d)) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
		} else {
			float _f,_ff;
			double _d,_dd;
			std::cout << "char: ";
			if (c < 32 || c > 126) {
				std::cout << "Non displayable" << std::endl;
			} else {
				std::cout << "\'" << c << "\'" << std::endl;
			}
			std::cout << "int: " << n << std::endl;
			_f=modff(f,&_ff); 
			if (_f != 0.0f)
				std::cout << "float: " << f << "f" << std::endl;
			else
				std::cout << "float: " << f << ".0f" << std::endl;
			_d=modf(d,&_dd); 
			if (_d != 0.0)
				std::cout << "double: " << d << std::endl;
			else
				std::cout << "double: " << d << ".0" << std::endl;
		}
	} else {
		std::cout << "Usage: ./" << *argv << " [ char | int | float | double ]" << std::endl;
	}
	return 0;
}
