#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ):
	Form("Robotomy Request Form", "Marvin", 72, 45) { }

RobotomyRequestForm::RobotomyRequestForm( std::string t ):
	Form("Robotomy Request Form", t, 72, 45) { }

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &cp ):
	Form(cp.getName(), cp.getTarget(), 72, 45) {
	*this = cp;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) { }

RobotomyRequestForm& RobotomyRequestForm::operator=( RobotomyRequestForm const& rhs ) {
	if (this != &rhs) {
		// TODO: implement
	}
	return *this;
}

void RobotomyRequestForm::execute( Bureaucrat const& b ) const {
	Form::execute(b);
	std::cout << "* DRILLING NOISES * -- Robotomy was ";
	if (rand()%100 < (50))
		std::cout << "successful" << std::endl;
	else
		std::cout << "unsuccessful" << std::endl;
}
