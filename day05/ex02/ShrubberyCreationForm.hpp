#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include <string>
#include "Form.hpp"

class ShrubberyCreationForm: public Form {

public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string );
	ShrubberyCreationForm( ShrubberyCreationForm const & );

	~ShrubberyCreationForm( void );

	ShrubberyCreationForm& operator=( ShrubberyCreationForm const& );

	void execute( Bureaucrat const& ) const;

private:

};

#endif /* SHRUBBERYCREATIONFORM_HPP */
