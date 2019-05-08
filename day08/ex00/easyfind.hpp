#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <string>

template <typename T>
unsigned long easyfind( T c, int n ) throw(std::exception) {
	typename T::iterator a = std::find(c.begin(), c.end(), n);
	if (a == c.end()) throw std::exception();
	return *a;
}

#endif /* EASYFIND_HPP */
