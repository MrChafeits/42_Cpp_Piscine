#include <iostream>
#include <stdexcept>
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

static void test(Bureaucrat b,
				 ShrubberyCreationForm f1,
				 RobotomyRequestForm f2,
				 PresidentialPardonForm f3) {
	try {
		b.signForm(f1);
        b.signForm(f2);
        b.signForm(f3);

        b.executeForm(f1);
        b.executeForm(f2);
        b.executeForm(f3);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main(void)
{
    Bureaucrat b1("B1", 71);
    Bureaucrat b2("B2", 42);
    Bureaucrat b3("B3", 1);
    ShrubberyCreationForm f1("SCF_A3");
    RobotomyRequestForm f2("RRF_B6");
    PresidentialPardonForm f3("PPF_C9");

    test(b1, f1, f2, f3);
    std::cout << std::endl;

    test(b2, f1, f2, f3);
    std::cout << std::endl;

    test(b3, f1, f2, f3);
    std::cout << std::endl;
}
