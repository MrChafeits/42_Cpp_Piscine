#ifndef INTERN_HPP
#define INTERN_HPP

#include <stdexcept>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

public:
	Intern( void );
	Intern( Intern const & );

	~Intern( void );

	Intern& operator=( Intern const& );

	Form* makeForm(std::string n, std::string t);
	typedef Form* (Intern::*InternFp)(std::string);

private:
	Form* _searchForm(std::string n, std::string t);
	Form* _newPresForm(std::string t);
	Form* _newRoboForm(std::string t);
	Form* _newShrbForm(std::string t);

	InternFp _f[3];
	static std::string _n[3];
};

#endif /* INTERN_HPP */
