#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm: public Form {

public:
	RobotomyRequestForm( std::string );
	RobotomyRequestForm( RobotomyRequestForm const & );
	~RobotomyRequestForm( void );
	RobotomyRequestForm& operator=( RobotomyRequestForm const& );

	void action( Bureaucrat& ) throw(Form::GradeTooLowException);

private:
	std::string _target;

};

#endif /* ROBOTOMYREQUESTFORM_HPP */
