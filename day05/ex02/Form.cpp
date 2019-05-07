#include "Form.hpp"

Form::Form( void ):
	_name("Todo"),
	_gradeReqSign(150),
	_gradeReqExec(149),
	_signed(false) { }

Form::Form( std::string n, int s, int e )
	throw(Form::GradeTooHighException, Form::GradeTooLowException):
	_name(n),
	_gradeReqSign(s),
	_gradeReqExec(e),
	_signed(false) { }

Form::Form( Form const &cp ):
	_name(cp._name),
	_gradeReqSign(cp._gradeReqSign),
	_gradeReqExec(cp._gradeReqExec),
	_signed(cp._signed) { *this = cp; }

Form::~Form( void ) { }

Form& Form::operator=( Form const& rhs) {
	if (this != &rhs) {
		_signed = rhs._signed;
	}
	return *this;
}

std::string const& Form::getName( void ) const { return _name; }
int Form::getGradeReqSign( void ) const { return _gradeReqSign; }
int Form::getGradeReqExec( void ) const { return _gradeReqExec; }
bool Form::getFormState( void ) const { return _signed; }

bool Form::beSigned( Bureaucrat const& b ) throw(Form::GradeTooLowException) {
	if (b.getGrade() > _gradeReqSign) throw Form::GradeTooLowException();
	_signed = true;
	return true;
}

void Form::action( Bureaucrat const& e ) const throw(Form::GradeTooLowException) {
	if (e.getGrade() > _gradeReqExec)
		throw Form::GradeTooLowException();
	else
		std::cout << "Executing " << _name << std::endl;
}

std::ostream& operator<<( std::ostream& os, Form const& fm ) {
	os << fm.getName()
	   << " is"
	   << (fm.getFormState() ? " " : " not ")
	   << "signed"
	   << ", needs grade "
	   << fm.getGradeReqSign()
	   << " to sign, and "
	   << fm.getGradeReqExec()
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
