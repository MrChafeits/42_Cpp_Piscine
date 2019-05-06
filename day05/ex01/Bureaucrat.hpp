#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat {

public:
	class GradeTooHighException : public std::exception {
	public:
		GradeTooHighException( void );
		GradeTooHighException( GradeTooHighException const& );
		~GradeTooHighException( void ) throw();
		GradeTooHighException& operator=( GradeTooHighException const& );
		virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		GradeTooLowException( void );
		GradeTooLowException( GradeTooLowException const& );
		~GradeTooLowException( void ) throw();
		GradeTooLowException& operator=( GradeTooLowException const& );
		virtual const char*	what() const throw();
	};

	Bureaucrat( void );
	Bureaucrat( std::string, int ) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
	Bureaucrat( Bureaucrat const & );

	~Bureaucrat( void );

	Bureaucrat& operator=( Bureaucrat const& );

	int getGrade( void ) const;
	std::string const& getName( void ) const;

	void incGrade( void ) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
	void decGrade( void ) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
	void signForm( Form &f ) throw(Bureaucrat::GradeTooLowException);

private:
	int _grade;
	std::string const _name;

};

std::ostream& operator<<( std::ostream&, Bureaucrat const& );

#endif /* BUREAUCRAT_HPP */
