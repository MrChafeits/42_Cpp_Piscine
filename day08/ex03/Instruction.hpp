#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <iostream>
#include <string>
#include <vector>

class Instruction {

public:
	virtual ~Instruction(void){};
	virtual void execute(std::string*, unsigned long*, int*, std::vector<Instruction*>&)=0;
	virtual int getId(void) const=0;
};

#endif /* INSTRUCTION_HPP */
#ifndef RIGHTANGLEBRACKET_HPP
#define RIGHTANGLEBRACKET_HPP

#include "Instruction.hpp"

class RightAngleBracket: public Instruction {

public:
	RightAngleBracket( void );
	RightAngleBracket( RightAngleBracket const & );
	~RightAngleBracket( void );
	RightAngleBracket& operator=( RightAngleBracket const& );

	void execute(std::string* s, int* p, std::vector<Instruction*>::iterator* i);

private:

};

#endif /* RIGHTANGLEBRACKET_HPP */
#ifndef LEFTANGLEBRACKET_HPP
#define LEFTANGLEBRACKET_HPP

#include "Instruction.hpp"

class LeftAngleBracket: public Instruction {

public:
	LeftAngleBracket( void );
	LeftAngleBracket( LeftAngleBracket const & );
	~LeftAngleBracket( void );
	LeftAngleBracket& operator=( LeftAngleBracket const& );

	void execute(std::string* s, int* p, std::vector<Instruction*>::iterator* i);

};

#endif /* LEFTANGLEBRACKET_HPP */
#ifndef ADDITIONSYMBOL_HPP
#define ADDITIONSYMBOL_HPP

#include "Instruction.hpp"

class AdditionSymbol: public Instruction {

public:
	AdditionSymbol( void );
	AdditionSymbol( AdditionSymbol const & );
	~AdditionSymbol( void );
	AdditionSymbol& operator=( AdditionSymbol const& );

	void execute(std::string* s, int* p, std::vector<Instruction*>::iterator* i);

};

#endif /* ADDITIONSYMBOL_HPP */
#ifndef FULLWIDTHHYPHEN_HPP
#define FULLWIDTHHYPHEN_HPP

#include "Instruction.hpp"

class FullWidthHyphen: public Instruction {

public:
	FullWidthHyphen( void );
	FullWidthHyphen( FullWidthHyphen const & );
	~FullWidthHyphen( void );
	FullWidthHyphen& operator=( FullWidthHyphen const& );

	void execute(std::string* s, int* p, std::vector<Instruction*>::iterator* i);

};

#endif /* FULLWIDTHHYPHEN_HPP */
#ifndef FULLSTOP_HPP
#define FULLSTOP_HPP

#include "Instruction.hpp"

class FullStop: public Instruction {

public:
	FullStop( void );
	FullStop( FullStop const & );
	~FullStop( void );
	FullStop& operator=( FullStop const& );

	void execute(std::string* s, int* p, std::vector<Instruction*>::iterator* i);
};

#endif /* FULLSTOP_HPP */
#ifndef ANTIAPOSTROPHE_HPP
#define ANTIAPOSTROPHE_HPP

#include "Instruction.hpp"

class AntiApostrophe: public Instruction {

public:
	AntiApostrophe( void );
	AntiApostrophe( AntiApostrophe const & );
	~AntiApostrophe( void );
	AntiApostrophe& operator=( AntiApostrophe const& );

	void execute(std::string* s, int* p, std::vector<Instruction*>::iterator* i);

};

#endif /* ANTIAPOSTROPHE_HPP */
#ifndef OPENSQUAREBRACKET_HPP
#define OPENSQUAREBRACKET_HPP

#include "Instruction.hpp"

class OpenSquareBracket: public Instruction {

public:
	OpenSquareBracket( void );
	OpenSquareBracket( OpenSquareBracket const & );
	~OpenSquareBracket( void );
	OpenSquareBracket& operator=( OpenSquareBracket const& );

	void execute(std::string*, unsigned long*, int*, std::vector<Instruction*>&);
	int getId(void)const;

private:
	int _id;
};

#endif /* OPENSQUAREBRACKET_HPP */
#ifndef CLOSESQUAREBRACKET_HPP
#define CLOSESQUAREBRACKET_HPP

#include "Instruction.hpp"

class CloseSquareBracket: public Instruction {

public:
	CloseSquareBracket( void );
	CloseSquareBracket( CloseSquareBracket const & );
	~CloseSquareBracket( void );
	CloseSquareBracket& operator=( CloseSquareBracket const& );

	void execute(std::string*, unsigned long*, int*, std::vector<Instruction*>&);
	int getId(void)const;

private:
	int _id;
};

#endif /* CLOSESQUAREBRACKET_HPP */
