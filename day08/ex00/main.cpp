#include <iostream>
#include <vector>
#include <array>
#include "easyfind.hpp"

int main() {
	int		a = 42;
	std::vector<int> v;
	for (int i = 0; i < 64; i++)
		v.push_back(64 - i);
	std::vector<int> j;
	for (int i = 0; i < 32; i++)
		j.push_back(i);
	std::array<int, 128> arr;
	for (int i = 0; i < 128; i++)
		arr[i] = i;
	std::array<int, 8192> a2;
	for (int i = 0; i < 8192; i++)
		a2[i] = i;
	std::cout << easyfind(a2, a) << std::endl;
	a2[42] = 41;

	try {std::cout << easyfind(v, a) << std::endl;}
	catch (std::exception &cp) {std::cout << "Number not found" << std::endl;}
	try {std::cout << easyfind(j, a) << std::endl;}
	catch (std::exception &cp) {std::cout << "Number not found" << std::endl;}
	try {std::cout << easyfind(arr, a) << std::endl;}
	catch (std::exception &cp) {std::cout << "Number not found" << std::endl;}
	try {std::cout << easyfind(a2, a) << std::endl;}
	catch (std::exception &cp) {std::cout << "Number not found" << std::endl;}
}
