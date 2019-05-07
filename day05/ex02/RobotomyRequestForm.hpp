#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class RobotomyRequestForm: public Form {

public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string );
	RobotomyRequestForm( RobotomyRequestForm const & );

	~RobotomyRequestForm( void );

	RobotomyRequestForm& operator=( RobotomyRequestForm const& );

	virtual void execute( Bureaucrat const& ) const;

private:

};

#endif /* ROBOTOMYREQUESTFORM_HPP */
