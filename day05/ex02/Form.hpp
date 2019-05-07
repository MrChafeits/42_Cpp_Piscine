#ifndef FORM_HPP
#define FORM_HPP
 
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

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

	Form( std::string, std::string, int, int )
		throw(Form::GradeTooHighException, Form::GradeTooLowException);
	Form( Form const & );

	~Form( void );

	Form& operator=( Form const& );

	std::string getName( void ) const;
	std::string getTarget( void ) const;
	int getSignGrade( void ) const;
	int getExecGrade( void ) const;

	bool getSigned( void ) const;
	bool beSigned( Bureaucrat const& ) throw(Form::GradeTooLowException);

	virtual void execute( Bureaucrat const& ) const = 0;

private:
	std::string const _name;
	std::string _target;
	int const _gradeSign;
	int const _gradeExec;
	bool _signed;

};

std::ostream& operator<<( std::ostream&, Form const& );

#endif /* FORM_HPP */
