#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ):
	Form("Presidential Pardon Form", "Zaphod Beeblebrox", 25, 5) { }

PresidentialPardonForm::PresidentialPardonForm( std::string t ):
	Form("Presidential Pardon Form", t, 25, 5) { }

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &cp ):
	Form("Presidential Pardon Form", "Zaphod Beeblebrox", 25, 5) { *this = cp; }

PresidentialPardonForm::~PresidentialPardonForm( void ) { }

PresidentialPardonForm& PresidentialPardonForm::operator=( PresidentialPardonForm const& ) {
	return *this;
} // TODO: implement

void PresidentialPardonForm::execute( Bureaucrat const& b ) const {
	Form::execute(b);
	std::cout << getTarget()
			  << " has been pardoned by President Zaphod Beeblebrox I"
			  << std::endl;
}
