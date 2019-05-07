#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm: public Form {

public:
	PresidentialPardonForm( std::string );
	PresidentialPardonForm( PresidentialPardonForm const & );
	~PresidentialPardonForm( void );
	PresidentialPardonForm& operator=( PresidentialPardonForm const& );

	void action( Bureaucrat& ) throw(Form::GradeTooLowException);

private:
	std::string _target;

};

#endif /* PRESIDENTIALPARDONFORM_HPP */
