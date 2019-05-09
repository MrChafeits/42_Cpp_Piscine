#include "AInstruction.hpp"

ClosingBracket::ClosingBracket( void )
{
	c = ']';
}

ClosingBracket::ClosingBracket( ClosingBracket const & cp) { *this = cp; }
ClosingBracket::~ClosingBracket( void ) { }
ClosingBracket& ClosingBracket::operator=( ClosingBracket const &) { return *this; }

void		ClosingBracket::execute(unsigned char (&tape)[TAPE_SIZE], std::vector<AInstruction *>&v, unsigned long *i, int *j)
{
	unsigned long		count = 1;

	if (tape[*j] == 0)
		return ;
	while (*i > 0 && count)
	{
		*i = *i - 1;
		if (v[*i]->getCh() == ']')
			++count;
		else if (v[*i]->getCh() == '[')
			--count;
	}
}

char		ClosingBracket::getCh( void ) const
{
	return (c);
}

OpeningBracket::OpeningBracket( void )
{
	c = '[';
}

OpeningBracket::OpeningBracket( OpeningBracket const & cp) { *this = cp; }
OpeningBracket::~OpeningBracket( void ) { }
OpeningBracket& OpeningBracket::operator=( OpeningBracket const &) { return *this; }

void	OpeningBracket::execute(unsigned char (&tape)[TAPE_SIZE], std::vector<AInstruction *> &v, unsigned long *i, int *j)
{
	unsigned long		count = -1;
	
	if (tape[*j] != 0)
		return ;
	while (*i < v.size() && count)
	{
		*i = *i + 1;
		if (v[*i]->getCh() == ']')
			++count;
		else if (v[*i]->getCh() == '[')
			--count;
	}
}

char	OpeningBracket::getCh( void ) const
{
	return (c);
}

Out::Out( void ) { c = '.'; }
Out::Out( Out const & cp) { *this = cp; }
Out::~Out( void ) { }
Out& Out::operator=( Out const &) { return *this; }

void	Out::execute(unsigned char (&tape)[TAPE_SIZE], std::vector<AInstruction *>&, unsigned long *, int *j)
{
	std::cout << static_cast<char>(tape[*j]);
}

char		Out::getCh( void ) const
{
	return (c);
}

PtrDec::PtrDec( void ) { c = '<'; }
PtrDec::PtrDec( PtrDec const & cp) { *this = cp; }
PtrDec::~PtrDec( void ) { }
PtrDec& PtrDec::operator=( PtrDec const &) { return *this; }

void	PtrDec::execute(unsigned char (&)[TAPE_SIZE], std::vector<AInstruction *>&, unsigned long *, int *j)
{
	if (*j > 0)
		*j = *j - 1;
}

char		PtrDec::getCh( void ) const
{
	return (c);
}

PtrInc::PtrInc( void ) { c = '>'; }
PtrInc::PtrInc( PtrInc const & cp) { *this = cp; }
PtrInc::~PtrInc( void ) { }
PtrInc& PtrInc::operator=( PtrInc const &) { return *this; }

void	PtrInc::execute(unsigned char (&)[TAPE_SIZE], std::vector<AInstruction *>&, unsigned long *, int *j)
{
	if (*j < TAPE_SIZE)
		*j = *j + 1;
}

char		PtrInc::getCh( void ) const
{
	return (c);
}

TakeInput::TakeInput( void ) { }
TakeInput::TakeInput( TakeInput const & cp) { *this = cp; }
TakeInput::~TakeInput( void ) { }
TakeInput& TakeInput::operator=( TakeInput const &) { return *this; }

void	TakeInput::execute(unsigned char (&tape)[TAPE_SIZE], std::vector<AInstruction *>&, unsigned long *, int *j)
{
	char	tmp;

	std::cout << std::endl << "> ";
	std::cin >> tmp;
	tape[*j] = tmp;
}

char		TakeInput::getCh( void ) const
{
	return (c);
}

ValDec::ValDec( void ) { c = '-'; }
ValDec::ValDec( ValDec const & cp) { *this = cp; }
ValDec::~ValDec( void ) { }
ValDec& ValDec::operator=( ValDec const &) { return *this; }

void	ValDec::execute(unsigned char (&tape)[TAPE_SIZE], std::vector<AInstruction *>&, unsigned long *, int *j)
{
	tape[*j] = tape[*j] - 1;
}

char		ValDec::getCh( void ) const
{
	return (c);
}

ValInc::ValInc( void ) { c = '+'; }
ValInc::ValInc( ValInc const & cp) { *this = cp; }
ValInc::~ValInc( void ) { }
ValInc& ValInc::operator=( ValInc const &) { return *this; }

void	ValInc::execute(unsigned char (&tape)[TAPE_SIZE], std::vector<AInstruction *>&, unsigned long *, int *j)
{
	tape[*j] = tape[*j] + 1;
}

char		ValInc::getCh( void ) const
{
	return (c);
}
