#include <iostream>

template <class T>
void iter(T const* arr, int l, void (*f)(T)) {
	for (int i=0;i<l;i++){ f(arr[i]);}
}

template <class T>
void p(T const a) { std::cout << a << std::endl; }

int main() {
	int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	std::string arrr[] = {"h",
						  "hh",
						  "hhh",
						  "hhhh"};

	iter(arr, 16, p);
	iter(arrr, 4, p);
}
