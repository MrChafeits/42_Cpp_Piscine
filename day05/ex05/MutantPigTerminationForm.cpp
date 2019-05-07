#include "MutantPigTerminationForm.hpp"

MutantPigTerminationForm::MutantPigTerminationForm( void ):
	Form("Mutant Pig Termination Form", "Piglet", 130, 50) { }

MutantPigTerminationForm::MutantPigTerminationForm( std::string t ):
	Form("Mutant Pig Termination Form", t, 130, 50) { }

MutantPigTerminationForm::MutantPigTerminationForm( MutantPigTerminationForm const &cp ):
	Form("Mutant Pig Termination Form", "Piglet", 130, 50) { *this = cp; }

MutantPigTerminationForm::~MutantPigTerminationForm( void ) { }

MutantPigTerminationForm& MutantPigTerminationForm::operator=( MutantPigTerminationForm const& ) {
	return *this;
} // TODO: implement

void MutantPigTerminationForm::execute( Bureaucrat const& b ) const {
	Form::execute(b);
	std::cout << "That'll do, "
			  << getTarget()
			  << ". That'll do..."
			  << std::endl;
}
