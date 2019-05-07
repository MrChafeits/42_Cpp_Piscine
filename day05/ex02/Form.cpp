#include "Form.hpp"

Form::Form( std::string n, std::string t, int s, int e )
	throw(Form::GradeTooHighException, Form::GradeTooLowException):
	_name(n),
	_target(t),
	_gradeSign(s),
	_gradeExec(e),
	_signed(false) { }

Form::Form( Form const &cp ):
	_name(cp._name),
	_target(cp._target),
	_gradeSign(cp._gradeSign),
	_gradeExec(cp._gradeExec),
	_signed(cp._signed) { *this = cp; }

Form::~Form( void ) { }

Form& Form::operator=( Form const& rhs) {
	if (this != &rhs) {
		_signed = rhs._signed;
	}
	return *this;
}

std::string Form::getName( void ) const { return _name; }
std::string Form::getTarget( void ) const { return _target; }
int Form::getSignGrade( void ) const { return _gradeSign; }
int Form::getExecGrade( void ) const { return _gradeExec; }
bool Form::getSigned( void ) const { return _signed; }

bool Form::beSigned( Bureaucrat const& b ) throw(Form::GradeTooLowException) {
	if (b.getGrade() > _gradeSign) throw Form::GradeTooLowException();
	_signed = true;
	return true;
}

void Form::execute( Bureaucrat const& e ) const {
	if (e.getGrade() > _gradeExec)
		throw Form::GradeTooLowException();
	else if (_signed)
		std::cout << "Executing " << _name << std::endl;
	else
		std::cout << "Form " << _name << " not signed" << std::endl;
}

std::ostream& operator<<( std::ostream& os, Form const& fm ) {
	os << fm.getName()
	   << " is"
	   << (fm.getSigned() ? " " : " not ")
	   << "signed"
	   << ", needs grade "
	   << fm.getSignGrade()
	   << " to sign, and "
	   << fm.getExecGrade()
	   << " to execute";
	return os;
}

Form::GradeTooHighException::GradeTooHighException( void ) { }
Form::GradeTooHighException::GradeTooHighException( GradeTooHighException const &cp ) { *this = cp; }
Form::GradeTooHighException::~GradeTooHighException( void ) throw() { }
Form::GradeTooHighException& Form::GradeTooHighException::operator=( GradeTooHighException const& ) {
	return *this;
}
const char	*Form::GradeTooHighException::what( void ) const throw() {
	return "Grade too high";
}

Form::GradeTooLowException::GradeTooLowException( void ) { }
Form::GradeTooLowException::GradeTooLowException( GradeTooLowException const &cp ) { *this = cp; }
Form::GradeTooLowException::~GradeTooLowException( void ) throw() { }
Form::GradeTooLowException& Form::GradeTooLowException::operator=( GradeTooLowException const& ) {
	return *this;
}
const char	*Form::GradeTooLowException::what( void ) const throw() {
	return "Grade too low";
}
