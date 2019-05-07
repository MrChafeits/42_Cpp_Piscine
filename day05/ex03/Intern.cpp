#include "Intern.hpp"

Intern::Intern( void ) {
	_f[0] = &Intern::_newPresForm;
	_f[1] = &Intern::_newRoboForm;
	_f[2] = &Intern::_newShrbForm;
}

Intern::Intern( Intern const &cp ) { *this = cp; }

Intern::~Intern( void ) { }

Intern& Intern::operator=( Intern const& ) { return *this; } // TODO: implement

std::string Intern::_n[3] = {"presidential pardon",
							 "robotomy request",
							 "shrubbery creation"};

Form* Intern::makeForm( std::string n, std::string t ) {
	try {
		return _searchForm(n, t);
	} catch (std::exception &e) {
		std::cout << n << " form not found" << std::endl;
		return nullptr;
	}
}

Form* Intern::_searchForm(std::string n, std::string t) {
	for (int i = 0; i < 3; i++) {
		if (n == _n[i]) {
			std::cout << "Intern creates " << _n[i] << std::endl;
			return (this->*_f[i])(t);
		}
	}
	std::cout << n << " form not found" << std::endl;
	return nullptr;
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
