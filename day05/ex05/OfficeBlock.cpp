#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock( void ): _i(nullptr), _s(nullptr), _e(nullptr) { }

OfficeBlock::OfficeBlock( Intern* i, Bureaucrat* s, Bureaucrat* e ):
	_i(i),
	_s(s),
	_e(e) { }

OfficeBlock::OfficeBlock( OfficeBlock const &cp ) { *this = cp; }

OfficeBlock::~OfficeBlock( void ) { }

OfficeBlock& OfficeBlock::operator=( OfficeBlock const& ) { return *this; } // TODO: implement

void OfficeBlock::setIntern( Intern* i ) { _i = i; }
void OfficeBlock::setSigner( Bureaucrat* s ) { _s = s; }
void OfficeBlock::setExecutor( Bureaucrat* e ) { _e = e; }

void OfficeBlock::doBureaucracy( std::string n, std::string t ) {
	if (_i != nullptr && _s != nullptr && _e != nullptr) {
		try {
			Form* f = _i->makeForm(n,t);
			f->beSigned(*_s);
			f->execute(*_e);
		} catch (Intern::FormNotFoundException &e) {
			std::cout << n << " " << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
	} else {
		if (_i == nullptr)
			std::cout << "Intern ";
		if (_s == nullptr)
			std::cout << "Signer ";
		if (_e == nullptr)
			std::cout << "Executor ";
		throw OfficeBlock::EmptyPositionException();
	}
}

OfficeBlock::EmptyPositionException::EmptyPositionException( void ) { }
OfficeBlock::EmptyPositionException::EmptyPositionException( EmptyPositionException const &cp ) { *this = cp; }
OfficeBlock::EmptyPositionException::~EmptyPositionException( void ) throw() { }
OfficeBlock::EmptyPositionException& OfficeBlock::EmptyPositionException::operator=( EmptyPositionException const& ) { return *this; }
const char	*OfficeBlock::EmptyPositionException::what( void ) const throw() {
	return "position is empty";
}

