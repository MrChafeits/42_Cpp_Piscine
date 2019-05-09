#ifndef AINSTRUCTION_HPP
#define AINSTRUCTION_HPP

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#define TAPE_SIZE (32768)

class AInstruction {

public:
	virtual ~AInstruction( void ) { };
	virtual void execute(unsigned char (&tape)[TAPE_SIZE], std::vector<AInstruction *>&, unsigned long *, int *) = 0;
	virtual char getCh( void ) const = 0;

};

class ClosingBracket: public AInstruction {

public:
	ClosingBracket( std::string );
	ClosingBracket( void );
	ClosingBracket( ClosingBracket const & cp);
	~ClosingBracket( void );
	ClosingBracket& operator=( ClosingBracket const &);

	void execute(unsigned char (&tape)[TAPE_SIZE], std::vector<AInstruction *>&, unsigned long *, int *);
	char getCh( void ) const;

private:
	char c;

};

class OpeningBracket : public AInstruction {

public:
	OpeningBracket( std::string );
	OpeningBracket( void );
	OpeningBracket( OpeningBracket const & cp);
	virtual ~OpeningBracket( void );
	OpeningBracket& operator=( OpeningBracket const &);

	void execute(unsigned char (&tape)[TAPE_SIZE], std::vector<AInstruction *>&, unsigned long *, int *);
	char getCh( void ) const;

private:
	char c;

};

class Out: public AInstruction {

public:
	Out( std::string );
	Out( void );
	Out( Out const & cp);
	~Out( void );
	Out& operator=( Out const &);

	void execute(unsigned char (&tape)[TAPE_SIZE], std::vector<AInstruction *>&, unsigned long *, int *);
	char getCh( void ) const;

private:
	char c;

};

class PtrDec: public AInstruction {

public:
	PtrDec( std::string );
	PtrDec( void );
	PtrDec( PtrDec const & cp);
	~PtrDec( void );
	PtrDec& operator=( PtrDec const &);

	void execute(unsigned char (&tape)[TAPE_SIZE], std::vector<AInstruction *>&, unsigned long *, int *);
	char getCh( void ) const;

private:
	char c;

};

class PtrInc: public AInstruction {

public:
	PtrInc( std::string );
	PtrInc( void );
	PtrInc( PtrInc const & cp);
	~PtrInc( void );
	PtrInc& operator=( PtrInc const &);

	void execute(unsigned char (&tape)[TAPE_SIZE], std::vector<AInstruction *>&, unsigned long *, int *);
	char getCh( void ) const;

private:
	char c;

};

class TakeInput: public AInstruction {

public:
	TakeInput( std::string );
	TakeInput( void );
	TakeInput( TakeInput const & cp);
	~TakeInput( void );
	TakeInput& operator=( TakeInput const &);

	void execute(unsigned char (&tape)[TAPE_SIZE], std::vector<AInstruction *>&, unsigned long *, int *);
	char getCh( void ) const;

private:
	char c;

};

class ValDec: public AInstruction {

public:
	ValDec( std::string );
	ValDec( void );
	ValDec( ValDec const & cp);
	~ValDec( void );
	ValDec& operator=( ValDec const &);

	void execute(unsigned char (&tape)[TAPE_SIZE], std::vector<AInstruction *>&, unsigned long *, int *);
	char getCh( void ) const;

private:
	char c;

};

class ValInc: virtual public AInstruction {

public:
	ValInc( std::string );
	ValInc( void );
	ValInc( ValInc const & cp);
	~ValInc( void );
	ValInc& operator=( ValInc const &);

	void execute(unsigned char (&tape)[TAPE_SIZE], std::vector<AInstruction *>&, unsigned long *, int *);
	char getCh( void ) const;

private:
	char c;

};

#endif /* AINSTRUCTION_HPP */
