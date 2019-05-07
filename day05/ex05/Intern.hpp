#ifndef INTERN_HPP
#define INTERN_HPP

#include <stdexcept>
#include "Form.hpp"
#include "MutantPigTerminationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define NUMFORMS (4)
class Intern {

public:
	class FormNotFoundException : public std::exception {
	public:
		FormNotFoundException( void );
		FormNotFoundException( FormNotFoundException const& );
		~FormNotFoundException( void ) throw();
		FormNotFoundException& operator=( FormNotFoundException const& );
		virtual const char*	what() const throw();
	};

	Intern( void );
	Intern( Intern const & );

	~Intern( void );

	Intern& operator=( Intern const& );

	Form* makeForm(std::string n, std::string t);
	typedef Form* (Intern::*InternFp)(std::string);

private:
	Form* _searchForm(std::string n, std::string t);
	Form* _newPigtForm(std::string t);
	Form* _newPresForm(std::string t);
	Form* _newRoboForm(std::string t);
	Form* _newShrbForm(std::string t);

	InternFp _f[NUMFORMS];
	static std::string _n[NUMFORMS];
};

#endif /* INTERN_HPP */
