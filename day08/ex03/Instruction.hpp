#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

#define TAPE_SIZE (32768)

class Instruction {

public:
	virtual ~Instruction(void){};
	virtual void execute(unsigned char(&)[TAPE_SIZE], unsigned long*, int*, std::vector<Instruction*>&)=0;
	virtual int getId(void) const=0;

};

class RightAngleBracket: public Instruction {

public:
	RightAngleBracket( void );
	RightAngleBracket( RightAngleBracket const & );
	~RightAngleBracket( void );
	RightAngleBracket& operator=( RightAngleBracket const& );

	void execute(unsigned char(&)[TAPE_SIZE], unsigned long*, int*, std::vector<Instruction*>&);
	int getId(void)const;

private:
	int _id;

};

class LeftAngleBracket: public Instruction {

public:
	LeftAngleBracket( void );
	LeftAngleBracket( LeftAngleBracket const & );
	~LeftAngleBracket( void );
	LeftAngleBracket& operator=( LeftAngleBracket const& );

	void execute(unsigned char(&)[TAPE_SIZE], unsigned long*, int*, std::vector<Instruction*>&);
	int getId(void)const;

private:
	int _id;

};

class AdditionSymbol: public Instruction {

public:
	AdditionSymbol( void );
	AdditionSymbol( AdditionSymbol const & );
	~AdditionSymbol( void );
	AdditionSymbol& operator=( AdditionSymbol const& );

	void execute(unsigned char(&)[TAPE_SIZE], unsigned long*, int*, std::vector<Instruction*>&);
	int getId(void)const;

private:
	int _id;

};

class FullWidthHyphen: public Instruction {

public:
	FullWidthHyphen( void );
	FullWidthHyphen( FullWidthHyphen const & );
	~FullWidthHyphen( void );
	FullWidthHyphen& operator=( FullWidthHyphen const& );

	void execute(unsigned char(&)[TAPE_SIZE], unsigned long*, int*, std::vector<Instruction*>&);
	int getId(void)const;

private:
	int _id;

};

class FullStop: public Instruction {

public:
	FullStop( void );
	FullStop( FullStop const & );
	~FullStop( void );
	FullStop& operator=( FullStop const& );

	void execute(unsigned char(&)[TAPE_SIZE], unsigned long*, int*, std::vector<Instruction*>&);
	int getId(void)const;

private:
	int _id;

};

class AntiApostrophe: public Instruction {

public:
	AntiApostrophe( void );
	AntiApostrophe( AntiApostrophe const & );
	~AntiApostrophe( void );
	AntiApostrophe& operator=( AntiApostrophe const& );

	void execute(unsigned char(&)[TAPE_SIZE], unsigned long*, int*, std::vector<Instruction*>&);
	int getId(void)const;

private:
	int _id;

};

class OpenSquareBracket: public Instruction {

public:
	OpenSquareBracket( void );
	OpenSquareBracket( OpenSquareBracket const & );
	~OpenSquareBracket( void );
	OpenSquareBracket& operator=( OpenSquareBracket const& );

	void execute(unsigned char(&)[TAPE_SIZE], unsigned long*, int*, std::vector<Instruction*>&);
	int getId(void)const;

private:
	int _id;

};

class CloseSquareBracket: public Instruction {

public:
	CloseSquareBracket( void );
	CloseSquareBracket( CloseSquareBracket const & );
	~CloseSquareBracket( void );
	CloseSquareBracket& operator=( CloseSquareBracket const& );

	void execute(unsigned char(&)[TAPE_SIZE], unsigned long*, int*, std::vector<Instruction*>&);
	int getId(void)const;

private:
	int _id;

};

#endif /* INSTRUCTION_HPP */
