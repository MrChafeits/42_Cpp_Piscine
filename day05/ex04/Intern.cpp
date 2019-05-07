#include "Intern.hpp"

Intern::Intern( void ) {
	_f[0] = &Intern::_newPresForm;
	_f[1] = &Intern::_newRoboForm;
	_f[2] = &Intern::_newShrbForm;
	_f[3] = &Intern::_newPigtForm;
}

Intern::Intern( Intern const &cp ) { *this = cp; }

Intern::~Intern( void ) { }

Intern& Intern::operator=( Intern const& ) { return *this; } // TODO: implement

std::string Intern::_n[NUMFORMS] = {"presidential pardon",
									"robotomy request",
									"shrubbery creation",
									"mutant pig termination"};

Form* Intern::makeForm( std::string n, std::string t ) {
	try {
		return _searchForm(n, t);
	} catch (Intern::FormNotFoundException &e) {
		throw Intern::FormNotFoundException();
	}
}

Form* Intern::_searchForm(std::string n, std::string t) {
	for (int i = 0; i < NUMFORMS; i++) {
		if (n == _n[i]) {
			std::cout << "Intern creates " << _n[i] << std::endl;
			return (this->*_f[i])(t);
		}
	}
	throw Intern::FormNotFoundException();
}

Form* Intern::_newPresForm(std::string t) {
	return new PresidentialPardonForm(t);
}

Form* Intern::_newRoboForm(std::string t) {
	return new RobotomyRequestForm(t);
}

Form* Intern::_newShrbForm(std::string t) {
	return new ShrubberyCreationForm(t);
}

Form* Intern::_newPigtForm(std::string t) {
	return new MutantPigTerminationForm(t);
}

Intern::FormNotFoundException::FormNotFoundException( void ) { }
Intern::FormNotFoundException::FormNotFoundException( FormNotFoundException const &cp ) { *this = cp; }
Intern::FormNotFoundException::~FormNotFoundException( void ) throw() { }
Intern::FormNotFoundException& Intern::FormNotFoundException::operator=( FormNotFoundException const& ) { return *this; }
const char	*Intern::FormNotFoundException::what( void ) const throw() {
	return "form not found";
}
