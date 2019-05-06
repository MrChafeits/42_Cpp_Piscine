#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm: public Form {

public:
	ShrubberyCreationForm( std::string );
	ShrubberyCreationForm( ShrubberyCreationForm const & );
	~ShrubberyCreationForm( void );
	ShrubberyCreationForm& operator=( ShrubberyCreationForm const& );

	void action( Bureaucrat& ) throw(Form::GradeTooLowException);

private:
	std::string const _target;

};

#endif /* SHRUBBERYCREATIONFORM_HPP */
