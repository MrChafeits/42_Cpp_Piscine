#include "Instruction.hpp"

RightAngleBracket::RightAngleBracket( void ): _id('>') { }

RightAngleBracket::RightAngleBracket( RightAngleBracket const &cp ) { *this = cp; }

RightAngleBracket::~RightAngleBracket( void ) { }

RightAngleBracket& RightAngleBracket::operator=( RightAngleBracket const& ) { return *this; }

int RightAngleBracket::getId( void ) const {return _id;}

void RightAngleBracket::execute(unsigned char (&)[TAPE_SIZE], unsigned long*, int* p, std::vector<Instruction*>&) {
	if (*p < TAPE_SIZE)
		(*p)++;
}

LeftAngleBracket::LeftAngleBracket( void ): _id('<') { }

LeftAngleBracket::LeftAngleBracket( LeftAngleBracket const &cp ) { *this = cp; }

LeftAngleBracket::~LeftAngleBracket( void ) { }

LeftAngleBracket& LeftAngleBracket::operator=( LeftAngleBracket const& ) { return *this; }

int LeftAngleBracket::getId( void ) const {return _id;}

void LeftAngleBracket::execute(unsigned char (&)[TAPE_SIZE], unsigned long*, int* p, std::vector<Instruction*>&) {
	if (*p > 0)
		(*p)--;
}

AdditionSymbol::AdditionSymbol( void ): _id('+') { }

AdditionSymbol::AdditionSymbol( AdditionSymbol const &cp ) { *this = cp; }

AdditionSymbol::~AdditionSymbol( void ) { }

AdditionSymbol& AdditionSymbol::operator=( AdditionSymbol const& ) { return *this; }

int AdditionSymbol::getId( void ) const {return _id;}

void AdditionSymbol::execute(unsigned char (&t)[TAPE_SIZE], unsigned long*, int* p, std::vector<Instruction*>&) {
	if (*p >= 0 && *p < TAPE_SIZE)
		t[*p] = t[*p] + 1;
}

FullWidthHyphen::FullWidthHyphen( void ): _id('-') { }

FullWidthHyphen::FullWidthHyphen( FullWidthHyphen const &cp ) { *this = cp; }

FullWidthHyphen::~FullWidthHyphen( void ) { }

FullWidthHyphen& FullWidthHyphen::operator=( FullWidthHyphen const& ) { return *this; }

int FullWidthHyphen::getId( void ) const {return _id;}

void FullWidthHyphen::execute(unsigned char (&t)[TAPE_SIZE], unsigned long*, int* p, std::vector<Instruction*>&) {
	if (*p >= 0 && *p < TAPE_SIZE)
		t[*p] = t[*p] - 1;
}

FullStop::FullStop( void ): _id('.') { }

FullStop::FullStop( FullStop const &cp ) { *this = cp; }

FullStop::~FullStop( void ) { }

FullStop& FullStop::operator=( FullStop const& ) { return *this; }

int FullStop::getId( void ) const {return _id;}

void FullStop::execute(unsigned char (&t)[TAPE_SIZE], unsigned long*, int* p, std::vector<Instruction*>&) {
	if (*p >= 0 && *p < TAPE_SIZE)
		std::cout << t[*p];
}

AntiApostrophe::AntiApostrophe( void ): _id(',') { }

AntiApostrophe::AntiApostrophe( AntiApostrophe const &cp ) { *this = cp; }

AntiApostrophe::~AntiApostrophe( void ) { }

AntiApostrophe& AntiApostrophe::operator=( AntiApostrophe const& ) { return *this; }

int AntiApostrophe::getId( void ) const {return _id;}

void AntiApostrophe::execute(unsigned char (&t)[TAPE_SIZE], unsigned long*, int* p, std::vector<Instruction*>&) {
	if (*p >= 0 && *p < TAPE_SIZE)
		t[*p] = std::cin.get();
}

OpenSquareBracket::OpenSquareBracket( void ): _id('[') { }

OpenSquareBracket::OpenSquareBracket( OpenSquareBracket const &cp ) { *this = cp; }

OpenSquareBracket::~OpenSquareBracket( void ) { }

OpenSquareBracket& OpenSquareBracket::operator=( OpenSquareBracket const& ) { return *this; }

int OpenSquareBracket::getId( void ) const { return _id; }

void OpenSquareBracket::execute(unsigned char (&t)[TAPE_SIZE], unsigned long* n, int* p, std::vector<Instruction*>& i) {
	unsigned long c = -1;

	if (!t[*p]) {
		while (*n && *n < i.size() && c) {
			(*n)++;
			if (i[*n]->getId() == ']')
				c++;
			else if (i[*n]->getId() == '[')
				c--;
		}
	}
}

CloseSquareBracket::CloseSquareBracket( void ): _id(']') { }

CloseSquareBracket::CloseSquareBracket( CloseSquareBracket const &cp ) { *this = cp; }

CloseSquareBracket::~CloseSquareBracket( void ) { }

CloseSquareBracket& CloseSquareBracket::operator=( CloseSquareBracket const& ) { return *this; }

int CloseSquareBracket::getId( void ) const { return _id; }

void CloseSquareBracket::execute(unsigned char (&t)[TAPE_SIZE], unsigned long* n, int* p, std::vector<Instruction*>& i) {
	unsigned long c = 1;

	if (t[*p] != 0) {
		while (*n > 0 && c) {
			(*n)--;
			if (i[*n]->getId() == ']')
				c++;
			else if (i[*n]->getId() == '[')
				c--;
		}
	}
}
