#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class PresidentialPardonForm: public Form {

public:
	PresidentialPardonForm( void );
	PresidentialPardonForm( std::string );
	PresidentialPardonForm( PresidentialPardonForm const & );

	~PresidentialPardonForm( void );

	PresidentialPardonForm& operator=( PresidentialPardonForm const& );

	virtual void execute( Bureaucrat const& ) const;

private:

};

#endif /* PRESIDENTIALPARDONFORM_HPP */
