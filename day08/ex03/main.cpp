#include "Instruction.hpp"

// Instruction* addRightAngleBracket(){return new RightAngleBracket();}
// Instruction* addLeftAngleBracket(){return new LeftAngleBracket();}
// Instruction* addAdditionSymbol(){return new AdditionSymbol();}
// Instruction* addFullWidthHyphen(){return new FullWidthHyphen();}
// Instruction* addFullStop(){return new FullStop();}
// Instruction* addAntiApostrophe(){return new AntiApostrophe();}
// Instruction* addOpenSquareBracket(){return new OpenSquareBracket();}
// Instruction* addCloseSquareBracket(){return new CloseSquareBracket();}

void mindOpen(std::string f) {
	static unsigned char t[TAPE_SIZE] = {0};
	std::vector<Instruction*> i;
	std::fstream ifs(f);
	unsigned long n;
	char c=0;
	int p=0;

	while (ifs.get(c)) {
		switch (c) {
		case '+': i.push_back(new AdditionSymbol()); break;
		case ',': i.push_back(new AntiApostrophe()); break;
		case '-': i.push_back(new FullWidthHyphen()); break;
		case '.': i.push_back(new FullStop()); break;
		case '<': i.push_back(new LeftAngleBracket()); break;
		case '>': i.push_back(new RightAngleBracket()); break;
		case '[': i.push_back(new OpenSquareBracket()); break;
		case ']': i.push_back(new CloseSquareBracket()); break;
		default: break;
		}
	}
	ifs.close();
	for (n=0; n < i.size(); n++)
		i[n]->execute(t, &n, &p, i);
}

int main(int argc, char* argv[]) {
	int ret;
	if(argc == 2) {
		mindOpen(argv[1]);
		std::cout<<std::endl;
		ret = 0;
	} else {
		std::cout << "Usage: ./" << argv[0] << " [file]" << std::endl;
		ret = 1;
	}
	return ret;
}
