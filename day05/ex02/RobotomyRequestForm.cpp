#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string t ): Form("Robotomy Request Form", 72, 45), _target(t) { }

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &cp ) { *this = cp; }

RobotomyRequestForm::~RobotomyRequestForm( void ) { }

RobotomyRequestForm& RobotomyRequestForm::operator=( RobotomyRequestForm const& ) {
	return *this;
} // TODO: implement

void RobotomyRequestForm::action( Bureaucrat& b ) throw(Form::GradeTooLowException) {
	if (!(b.getGrade() > getGradeReqExec()) && beSigned(b)) {
		std::cout << "* DRILLING NOISES *" << std::endl << "Robotomy was ";
		if (rand()%100 < (50))
			std::cout << "successful" << std::endl;
		else
			std::cout << "unsuccessful" << std::endl;
	} else if (getFormState()) {
		throw Form::GradeTooLowException();
	}
}
