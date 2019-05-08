#include <iostream>

class Base {
public:
	virtual ~Base(void){}
};

class A: public Base{};
class B: public Base{};
class C: public Base{};

Base* generate(void) {
	switch(rand()%3) {
	case 0:
		std::cout << "Generating \'A\'" << std::endl;
		return new A();
		break;
	case 1:
		std::cout << "Generating \'B\'" << std::endl;
		return new B();
		break;
	case 2:
		std::cout << "Generating \'C\'" << std::endl;
		return new C();
		break;
	}
	std::cout << "Generating \'A\'" << std::endl;
	return new A();
}

void identifyPointedStick( Base* p ) {
	A* ack = dynamic_cast<A*>(p);
	if (ack)
		std::cout << "A" << std::endl;
	B* bep = dynamic_cast<B*>(p);
	if (bep)
		std::cout << "B" << std::endl;
	C* cak = dynamic_cast<C*>(p);
	if (cak)
		std::cout << "C" << std::endl;
}

void identifyReferentialHue( Base& p ) {
	A* ack = dynamic_cast<A*>(&p);
	if (ack)
		std::cout << "A" << std::endl;
	B* bep = dynamic_cast<B*>(&p);
	if (bep)
		std::cout << "B" << std::endl;
	C* cak = dynamic_cast<C*>(&p);
	if (cak)
		std::cout << "C" << std::endl;
}

int main() {
	Base* b = generate();
	identifyPointedStick(b);
	b = generate();
	identifyPointedStick(b);
	b = generate();
	identifyPointedStick(b);
	b = generate();
	identifyPointedStick(b);
	b = generate();
	identifyReferentialHue(*b);
	b = generate();
	identifyReferentialHue(*b);
	b = generate();
	identifyReferentialHue(*b);
	b = generate();
	identifyReferentialHue(*b);
}
