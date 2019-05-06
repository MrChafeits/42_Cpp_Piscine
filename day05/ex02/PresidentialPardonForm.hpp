#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm: public Form {

public:
	PresidentialPardonForm( void );
	PresidentialPardonForm( PresidentialPardonForm const & );
	~PresidentialPardonForm( void );
	PresidentialPardonForm& operator=( PresidentialPardonForm const& );

private:
	std::string _target;

};

#endif /* PRESIDENTIALPARDONFORM_HPP */
