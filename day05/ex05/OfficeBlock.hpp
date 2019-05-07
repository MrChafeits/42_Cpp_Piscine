#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

class OfficeBlock {

public:
	class EmptyPositionException : public std::exception {
	public:
		EmptyPositionException( void );
		EmptyPositionException( EmptyPositionException const& );
		~EmptyPositionException( void ) throw();
		EmptyPositionException& operator=( EmptyPositionException const& );
		virtual const char*	what() const throw();
	};


	OfficeBlock( void );
	OfficeBlock( Intern*, Bureaucrat*, Bureaucrat* );
	OfficeBlock( OfficeBlock const & );
	~OfficeBlock( void );
	OfficeBlock& operator=( OfficeBlock const& );

	void setIntern( Intern* );
	void setSigner( Bureaucrat* );
	void setExecutor( Bureaucrat* );

	void doBureaucracy( std::string, std::string );

private:
	Intern* _i;
	Bureaucrat* _s;
	Bureaucrat* _e;

};

#endif /* OFFICEBLOCK_HPP */
