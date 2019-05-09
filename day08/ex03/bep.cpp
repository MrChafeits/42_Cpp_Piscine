#include <fstream>
#include "Instruction.hpp"
#include "RightAngleBracket.hpp"
#include "LeftAngleBracket.hpp"
#include "AdditionSymbol.hpp"
#include "FullWidthHyphen.hpp"
#include "FullStop.hpp"
#include "AntiApostrophe.hpp"
#include "OpenSquareBracket.hpp"
#include "CloseSquareBracket.hpp"

Instruction* addRightAngleBracket(){return new RightAngleBracket();}
Instruction* addLeftAngleBracket(){return new LeftAngleBracket();}
Instruction* addAdditionSymbol(){return new AdditionSymbol();}
Instruction* addFullWidthHyphen(){return new FullWidthHyphen();}
Instruction* addFullStop(){return new FullStop();}
Instruction* addAntiApostrophe(){return new AntiApostrophe();}
Instruction* addOpenSquareBracket(){return new OpenSquareBracket();}
Instruction* addCloseSquareBracket(){return new CloseSquareBracket();}

void mindOpen(std::string f) {
	std::map<char, Instruction* (*)(void)> m;
	std::string s;
	int p=0;
	std::vector<Instruction*>::iterator i;
	std::vector<Instruction*> l;
	char c=0;
	std::fstream ifs(f);

	m['>'] = addRightAngleBracket;
	m['<'] = addLeftAngleBracket;
	m['+'] = addAdditionSymbol;
	m['-'] = addFullWidthHyphen;
	m['.'] = addFullStop;
	m[','] = addAntiApostrophe;
	m['['] = addOpenSquareBracket;
	m[']'] = addCloseSquareBracket;
	for (;ifs.get(c);)
		if (m.count(c))
			l.push_back(m[c]());
	for (i = l.begin(); i != l.end(); i++)
		(*i)->execute(&s, &p, &i);
	ifs.close();
}

int main(int argc, char* argv[]) {
	if(argc == 2) {
		mindOpen(argv[1]);
		std::cout<<std::endl;
	}
}
