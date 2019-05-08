#include <iostream>
#include <string>

template <class T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <class T>
T min(T& a, T& b) { return a < b ? a : b; }

template <class T>
T max(T& a, T& b) { return a > b ? a : b; }

int main( void ) {
	{
		int a=2, b=3;
		::swap(a,b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a,b) = " << ::min(a,b) << std::endl;
		std::cout << "max(a,b) = " << ::max(a,b) << std::endl;
		std::string c="chonkyboi1", d="chonkyboi2";
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c,d) = " << ::min(c,d) << std::endl;
		std::cout << "max(c,d) = " << ::max(c,d) << std::endl;
	} {
		long ai=2147483649, bi=-2147483649;
		::swap(ai,bi);
		std::cout << "ai = " << ai << ", bi = " << bi << std::endl;
		std::cout << "min(ai,bi) = " << ::min(ai,bi) << std::endl;
		std::cout << "max(ai,bi) = " << ::max(ai,bi) << std::endl;
		std::string cs="fsjeriour0923ef", ds="tufjo23982390jfsdjafsdjk";
		std::cout << "cs = " << cs << ", ds = " << ds << std::endl;
		std::cout << "min(cs,ds) = " << ::min(cs,ds) << std::endl;
		std::cout << "max(cs,ds) = " << ::max(cs,ds) << std::endl;
	}
}
