#ifndef MUTANTPIGTERMINATIONFORM_HPP
#define MUTANTPIGTERMINATIONFORM_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class MutantPigTerminationForm: public Form {

public:
	MutantPigTerminationForm( void );
	MutantPigTerminationForm( std::string );
	MutantPigTerminationForm( MutantPigTerminationForm const & );

	~MutantPigTerminationForm( void );

	MutantPigTerminationForm& operator=( MutantPigTerminationForm const& );

	virtual void execute( Bureaucrat const& ) const;

private:

};

#endif /* MUTANTPIGTERMINATIONFORM_HPP */
