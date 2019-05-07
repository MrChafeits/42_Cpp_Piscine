#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ):
	_grade(150),
	_name("John-Paper Space-Bureaucrat") { }

Bureaucrat::Bureaucrat( std::string n, int g )
	throw(Bureaucrat::GradeTooHighException,
		  Bureaucrat::GradeTooLowException): _grade(g), _name(n) {
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( Bureaucrat const &cp ):
	_grade(cp._grade),
	_name(cp._name) { }

Bureaucrat::~Bureaucrat( void ) { }

int Bureaucrat::getGrade( void ) const { return _grade; }

std::string const& Bureaucrat::getName( void ) const { return _name; }

void Bureaucrat::incGrade( void )
	throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException) {
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::decGrade( void )
	throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException) {
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

Bureaucrat& Bureaucrat::operator=( Bureaucrat const& ob ) {
	if (this != &ob) {
		_grade = ob._grade;
	}
	return *this;
}

std::ostream& operator<<( std::ostream& os, Bureaucrat const& br ) {
	os << br.getName() << ", bureaucrat grade " << br.getGrade();
	return os;
}

void Bureaucrat::signForm( Form &f ) throw(Bureaucrat::GradeTooLowException) {
	try {
		f.beSigned(*this);
		std::cout << this->getName() << " signs " << f.getName() << std::endl;
	} catch (Form::GradeTooLowException) {
		std::cout << getName()
				  << " grade is too low. Cannot sign "
				  << f.getName()
				  << std::endl;
	}
}

void Bureaucrat::executeForm( Form const& f ) const
	throw(Bureaucrat::GradeTooLowException) {
	if (f.getSigned()) {
		try {
			f.execute(*this);
			std::cout << getName() << " executes " << f.getName() << std::endl;
		} catch (Form::GradeTooLowException) {
			std::cout << getName()
					  << " grade too low to execute "
					  << f.getName()
					  << std::endl;
		}
	} else {
		std::cout << f.getName() << " requires a signature" << std::endl;
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException( void ) { }
Bureaucrat::GradeTooHighException::GradeTooHighException( GradeTooHighException const &cp ) { *this = cp; }
Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw() { }
Bureaucrat::GradeTooHighException& Bureaucrat::GradeTooHighException::operator=( GradeTooHighException const& ) { return *this; }
const char	*Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return "Grade too high";
}

Bureaucrat::GradeTooLowException::GradeTooLowException( void ) { }
Bureaucrat::GradeTooLowException::GradeTooLowException( GradeTooLowException const &cp ) { *this = cp; }
Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) throw() { }
Bureaucrat::GradeTooLowException& Bureaucrat::GradeTooLowException::operator=( GradeTooLowException const& ) { return *this; }
const char	*Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return "Grade too low";
}

