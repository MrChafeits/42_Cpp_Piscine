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

	Form( void );
	Form( std::string, int, int )throw(Form::GradeTooHighException, Form::GradeTooLowException);
	Form( Form const & );

	~Form( void );

	Form& operator=( Form const& );

	std::string const& getName( void ) const;
	int getGradeReqSign( void ) const;
	int getGradeReqExec( void ) const;
	bool getFormState( void ) const;
	bool beSigned( Bureaucrat const& ) throw(Form::GradeTooLowException);
	void action( Bureaucrat const& ) const throw(Form::GradeTooLowException);

private:
	std::string const _name;
	int const _gradeReqSign;
	int const _gradeReqExec;
	bool _signed;

};

std::ostream& operator<<( std::ostream&, Form const& );

#endif /* FORM_HPP */
