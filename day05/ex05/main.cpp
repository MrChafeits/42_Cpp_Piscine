#include <iostream>
#include <stdexcept>
#include "Form.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "OfficeBlock.hpp"

int main(void) {
	Intern id;
	Bureaucrat h = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat b = Bureaucrat("Bobby Bobson", 123);
	OfficeBlock ob;

	ob.setIntern(&id);
	ob.setSigner(&b);
	ob.setExecutor(&h);
	try {
		ob.doBureaucracy("mutant pig termination", "Pigley");
	} catch (OfficeBlock::EmptyPositionException &e) {
		std::cout << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cout << "FUCKING PANIC" << std::endl << e.what() << std::endl;
	}
}
