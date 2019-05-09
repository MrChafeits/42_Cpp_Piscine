#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <iostream>
#include <stack>
#include <string>

template <typename T>
class MutantStack: public std::stack<T> {

public:
	MutantStack(void) {};
	MutantStack(MutantStack const& cp) {*this = cp;};
	~MutantStack(void) {};
	MutantStack& operator=(MutantStack const& rh) {if(this!=&rh) this=rh;};

	typedef typename std::deque<T>::iterator iterator;
	iterator begin(void) {return std::begin(this->c);}
	iterator end(void) {return std::end(this->c);}

private:

};

#endif /* MUTANTSTACK_HPP */
