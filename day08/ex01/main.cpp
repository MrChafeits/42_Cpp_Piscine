#include "span.hpp"

int main() {
	{
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} try {
		Span a(15);
		static_cast<void>(a);
		a.addNumber(9);
		std::cout << "Added 9" << std::endl;
		Span b(a);
		b.addNumber(1);
		std::cout << "Longest: " << b.longestSpan() << std::endl;
		std::cout << "Shortest: " << b.shortestSpan() << std::endl;
		b.addNumber(7);
		std::cout << "Longest: " << b.longestSpan() << std::endl;
		std::cout << "Shortest: " << b.shortestSpan() << std::endl;
		b.addNumber(19, 30);
		std::cout << "Longest: " << b.longestSpan() << std::endl;
		std::cout << "Shortest: " << b.shortestSpan() << std::endl;
		b.addNumber(8);
	} catch (Span::BadSizeException &e) {
		std::cout << "Use the good size 🅱️ i" << std::endl;
	} try {
		Span a(-1235);
		a.addNumber(1, -23489);
		std::cout << "Longest: " << a.longestSpan() << std::endl;
		std::cout << "Shortest: " << a.shortestSpan() << std::endl;
	} catch (Span::BadSizeException &e) {
		std::cout << "Bad size found UwU" << std::endl;
	}
}
