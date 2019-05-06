#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string t ):
	Form("Shrubbery Creation Form", 145, 137),
	_target(t) { }

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &cp ) {
	*this = cp;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) { }

ShrubberyCreationForm& ShrubberyCreationForm::operator=( ShrubberyCreationForm const& ) {
	return *this;
} // TODO: implement

void ShrubberyCreationForm::action( Bureaucrat& b ) throw(Form::GradeTooLowException) {
	if (!(b.getGrade() > getGradeReqExec()) && beSigned(b)) {
		std::string f = _target + "_shrubbery";
		std::ofstream ofs;

		ofs.open(f.c_str(), std::ios::out);
		if (!ofs.is_open()) {
			std::cout << "File open error" << std::endl;
			return;
		}
		ofs << "            .        +          .      .          ." << std::endl;
		ofs << "     .            _        .                    ." << std::endl;
		ofs << "  ,              /;-._,-.____        ,-----.__" << std::endl;
		ofs << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
		ofs << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl;
		ofs << "                      ,    `./  \\:. `.   )==-\'  ." << std::endl;
		ofs << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl;
		ofs << ".           \\/:/`-\' , ,\\ \'` ` `   ): , /_  -o" << std::endl;
		ofs << "       .    /:+- - + +- : :- + + -:\'  /(o-) \\)     ." << std::endl;
		ofs << "  .      ,=\':  \\    ` `/` \' , , ,:\' `\'--\".--\"---._/`7" << std::endl;
		ofs << "   `.   (    \\: \\,-._` ` + \'\\, ,\"   _,--._,---\":.__/" << std::endl;
		ofs << "              \\:  `  X` _| _,\\/\'   .-\'" << std::endl;
		ofs << ".               \":._:`\\____  /:\'  /      .           ." << std::endl;
		ofs << "                    \\::.  :\\/:'  /              +" << std::endl;
		ofs << "   .                 `.:.  /:'  }      ." << std::endl;
		ofs << "           .           ):_(:;   \\           ." << std::endl;
		ofs << "                      /:. _/ ,  |" << std::endl;
		ofs << "                   . (|::.     ,`                  ." << std::endl;
		ofs << "     .                |::.    {\\" << std::endl;
		ofs << "                      |::.\\  \\ `." << std::endl;
		ofs << "                      |:::(\\    |" << std::endl;
		ofs << "              O       |:::/{ }  |                  (o" << std::endl;
		ofs << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl;
		ofs << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;
		ofs << "      ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~" << std::endl;
	} else if (this->getFormState()) {
		throw Form::GradeTooLowException();
	}
}
