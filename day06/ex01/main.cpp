#include <cstdlib>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <string>

// [00 00 00 00 00 00 00 00] 00 00 00 00 [00 00 00 00 00 00 00 00]

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

void* serialize( void ) {
	register int i;
	char* n = new char[20];

	for (i=0;i<8;i++) {
		n[i] = (rand()%95)+32;
		n[i+12] = (rand()%95)+32;
	}
	*reinterpret_cast<int*>(&n[i]) = rand();
	return n;
}

Data* deserialize( void* raw ) {
	register int i;
	std::string s1 = "00000000";
	std::string s2 = "00000000";
	char* b = reinterpret_cast<char*>(raw);
	Data* d = new Data;

	for (i=0;i<8;i++)
		s1[i] = b[i];
	d->s1 = s1;
	d->n = *reinterpret_cast<int*>(&b[i]);
	for (i=0;i<8;i++)
		s2[i] = b[i+12];
	d->s2 = s2;
	return d;
}

static void test() {
	void *raw = serialize();
	std::cout << "raw : ";
	std::cout.write(static_cast<const char*>(raw), 20);
	std::cout << std::endl;
	Data *d = deserialize(raw);
	std::cout << "Data: ";
	std::cout.write(reinterpret_cast<const char*>(d), sizeof(*d));
	std::cout << std::endl << d->s1 << std::endl;
	std::cout << d->s2 << std::endl;
	std::cout << d->n << std::endl;
	std::cout << std::endl;
}

int main() {
	srand(time(0));
	test();
	test();
	test();
	return (0);
}
