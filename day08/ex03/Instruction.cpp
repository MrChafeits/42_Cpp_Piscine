#include "Instruction.hpp"
//TODO: this
#include "RightAngleBracket.hpp"

RightAngleBracket::RightAngleBracket( void ) { }

RightAngleBracket::RightAngleBracket( RightAngleBracket const &cp ) { *this = cp; }

RightAngleBracket::~RightAngleBracket( void ) { }

RightAngleBracket& RightAngleBracket::operator=( RightAngleBracket const& ) { return *this; } // TODO: implement

void RightAngleBracket::execute(std::string* s, int* p, std::vector<Instruction*>::iterator* i) {(void)s;(void)i;(*p)++;}
#include "LeftAngleBracket.hpp"

LeftAngleBracket::LeftAngleBracket( void ) { }

LeftAngleBracket::LeftAngleBracket( LeftAngleBracket const &cp ) { *this = cp; }

LeftAngleBracket::~LeftAngleBracket( void ) { }

LeftAngleBracket& LeftAngleBracket::operator=( LeftAngleBracket const& ) { return *this; } // TODO: implement

void LeftAngleBracket::execute(std::string* s, int* p, std::vector<Instruction*>::iterator* i) {(void)s;(void)i;(*p)--;}
#include "AdditionSymbol.hpp"

AdditionSymbol::AdditionSymbol( void ) { }

AdditionSymbol::AdditionSymbol( AdditionSymbol const &cp ) { *this = cp; }

AdditionSymbol::~AdditionSymbol( void ) { }

AdditionSymbol& AdditionSymbol::operator=( AdditionSymbol const& ) { return *this; } // TODO: implement

void AdditionSymbol::execute(std::string* s, int* p, std::vector<Instruction*>::iterator* i) {(void)i;(*s)[*p]++;}
#include "FullWidthHyphen.hpp"

FullWidthHyphen::FullWidthHyphen( void ) { }

FullWidthHyphen::FullWidthHyphen( FullWidthHyphen const &cp ) { *this = cp; }

FullWidthHyphen::~FullWidthHyphen( void ) { }

FullWidthHyphen& FullWidthHyphen::operator=( FullWidthHyphen const& ) { return *this; } // TODO: implement

void FullWidthHyphen::execute(std::string* s, int* p, std::vector<Instruction*>::iterator* i) {(void)i;(*s)[*p]--;}
#include "FullStop.hpp"

FullStop::FullStop( void ) { }

FullStop::FullStop( FullStop const &cp ) { *this = cp; }

FullStop::~FullStop( void ) { }

FullStop& FullStop::operator=( FullStop const& ) { return *this; } // TODO: implement

void FullStop::execute(std::string* s, int* p, std::vector<Instruction*>::iterator* i){(void)i;std::cout<<(*s)[*p];}
#include "AntiApostrophe.hpp"

AntiApostrophe::AntiApostrophe( void ) { }

AntiApostrophe::AntiApostrophe( AntiApostrophe const &cp ) { *this = cp; }

AntiApostrophe::~AntiApostrophe( void ) { }

AntiApostrophe& AntiApostrophe::operator=( AntiApostrophe const& ) { return *this; } // TODO: implement

void AntiApostrophe::execute(std::string* s, int* p, std::vector<Instruction*>::iterator* i) {(void)i;(*s)[*p]=std::cin.get();}
#include "OpenSquareBracket.hpp"
#include "CloseSquareBracket.hpp"

OpenSquareBracket::OpenSquareBracket( void ) { }

OpenSquareBracket::OpenSquareBracket( OpenSquareBracket const &cp ) { *this = cp; }

OpenSquareBracket::~OpenSquareBracket( void ) { }

OpenSquareBracket& OpenSquareBracket::operator=( OpenSquareBracket const& ) { return *this; } // TODO: implement

void OpenSquareBracket::execute(std::string* s, unsigned long* n, int* p, std::vector<Instruction*>& v) {
	unsigned long c=-1;
	if ((*s)[*p]) {
		while (*n < v.size() && c) {
			(*n)--;
			if (v[*n]->getId() == ']')
				++c;
			else if (v[*n]->getId() == '[')
				--c;
		}
	}
}

int OpenSquareBracket::getId(){return _id;}#include "OpenSquareBracket.hpp"
#include "CloseSquareBracket.hpp"

CloseSquareBracket::CloseSquareBracket( void ): _id('[') { }

CloseSquareBracket::CloseSquareBracket( CloseSquareBracket const &cp ) { *this = cp; }

CloseSquareBracket::~CloseSquareBracket( void ) { }

CloseSquareBracket& CloseSquareBracket::operator=( CloseSquareBracket const& ) { return *this; } // TODO: implement
void CloseSquareBracket::execute(std::string* s, unsigned long* n, int* p, std::vector<Instruction*>& v) {
	unsigned long c=1;
	if ((*s)[*p]) {
		while (*n > 0 && c) {
			(*n)--;
			if (v[*n]->getId() == ']')
				++c;
			else if (v[*n]->getId() == '[')
				--c;
		}
	}
}

int CloseSquareBracket::getId()const{return _id;}
