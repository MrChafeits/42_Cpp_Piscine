#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

template <class T>
class Array {
public:
	Array<T>( void ): _array(NULL), _size(0) { }
	Array<T>( unsigned n ): _array(new T[n]), _size(n) { }
	Array<T>( Array const& r ) { *this = r; }
	~Array<T>( void ) { }
	Array<T>&operator=( Array const& r ) {
		if (this != &r) {
			_size = r._size;
			delete[] _array;
			_array = new T[_size];
			for (int i=0;i<_size;i++) _array[i] = r._array[i];
		}}
	T& operator[](unsigned i) {
		if (i >= _size) throw std::exception();
		return _array[i];
	}
	unsigned size() const { return _size; }

private:
	T* _array;
	unsigned _size;
};

#endif /* ARRAY_HPP */
