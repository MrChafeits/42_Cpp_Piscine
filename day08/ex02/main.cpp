#include "mutantstack.hpp"

int main() {
	{
		MutantStack<int> mstack;
		std::cout << mstack.size() << std::endl;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(7);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "Copying stack" << std::endl;
		std::stack<int> s(mstack);
		MutantStack<int>::iterator it2 = mstack.begin();
		MutantStack<int>::iterator ite2 = mstack.end();
		++it2;
		--it2;
		while (it2 != ite2) {
			std::cout << *it2 << std::endl;
			++it2;
		}
	}
}
