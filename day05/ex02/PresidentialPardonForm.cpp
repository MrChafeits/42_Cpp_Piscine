#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string t ):
	Form("Presidential Pardon Form", 25, 5),
	_target(t) { }

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &cp ) { *this = cp; }

PresidentialPardonForm::~PresidentialPardonForm( void ) { }

PresidentialPardonForm& PresidentialPardonForm::operator=( PresidentialPardonForm const& ) { return *this; } // TODO: implement

void PresidentialPardonForm::action( Bureaucrat& b ) throw(Form::GradeTooLowException) {
	if (!(b.getGrade() > getGradeReqExec()) && beSigned(b)) {
		std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
	} else if (getFormState()) {
		throw Form::GradeTooLowException();
	}
}
