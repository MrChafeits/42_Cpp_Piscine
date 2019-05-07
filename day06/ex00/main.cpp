#include <cstdlib>
#include <iostream>
#include <string>

// static_cast<> - similar to c-style cast
// dynamic_cast<> - evaluated at runtime
// reinterpret_cast<> - bit smoosh with no conversion
// const_cast<> - fuckoff const n lemme convert

union _argsu {
	char c;
	int i;
	float f;
	double d;
};

typedef union _argsu args;

void convertScalar(std::string s) {
}

static std::string _f[8] = {
	"-inf",
	"+inf",
	"inf",
	"nan",
	"-inff",
	"+inff",
	"inff",
	"nanf",
};

void convertFloaty(std::string s) {
}

int main(int argc, char* argv[]) {
	register int i;
	std::string s;
	args a;

	if (argc > 1) {
		for (i=0; i<argc; i++) {
			s = std::string(argv[i]);
			if (s.find('\'') && s.size() == 3) {
				a.c = static_cast<char>(s[1]);
			} else if (s.find('.')) {
				if (s.find('f')) {
					a.f = atof(s.c_str());
				} else {
					a.d = strtod(s.c_str(), NULL);
				}
			} else {
				if (s.find('-')) {
					if (s.find('i')) {
					}
				} else if (s.find('+')) {
					if (s.find('i')) {}
				} else {
					if (s.find('i')) {
					} else if (s == "nan") {
					} else if (s == "nanf") {
					}
				}
				//TODO
			}
		}
	} else {
	}
	return 0;
}
