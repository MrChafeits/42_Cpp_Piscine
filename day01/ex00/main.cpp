#include "Pony.hpp"
#include <iostream>

void ponyOnTheHeap(void)
{
	Pony *horace = new Pony();
	std::cout << "horace = " << horace << std::endl;
	horace->setAge("23.2475");
	horace->setCoat("Sunburned Redwood Brown");
	horace->setMane("Periwinkle Blue");
	horace->setName("Gerald Dirk Horace VI");
	std::cout << "Age: " << horace->getAge() << std::endl;
	std::cout << "Coat: " << horace->getCoat() << std::endl;
	std::cout << "Mane: " << horace->getMane() << std::endl;
	std::cout << "Name: " << horace->getName() << std::endl;
	delete horace;
}

void ponyOnTheStack(void)
{
	Pony harold;
	std::cout << "&harold = " << &harold << std::endl;
	harold.setAge("13.5345");
	harold.setCoat("Slippery Birch Tan");
	harold.setMane("Parched Spicy Salmon");
	harold.setName("Charles Humphrey Harold VII");
	std::cout << "Age: " << harold.getAge() << std::endl;
	std::cout << "Coat: " << harold.getCoat() << std::endl;
	std::cout << "Mane: " << harold.getMane() << std::endl;
	std::cout << "Name: " << harold.getName() << std::endl;
}

int main(void)
{
	std::cout << "--- ponyOnTheHeap ---" << std::endl;
	ponyOnTheHeap();
	std::cout << std::endl << "--- ponyOnTheStack ---" << std::endl;
	ponyOnTheStack();
	// while(1);
}
