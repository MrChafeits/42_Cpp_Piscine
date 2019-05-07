#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ):
	Form("Shrubbery Creation Form", "shrub", 145, 137) { }

ShrubberyCreationForm::ShrubberyCreationForm( std::string t ):
	Form("Shrubbery Creation Form", t, 145, 137) { }

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &cp ):
	Form("Shrubbery Creation Form", "shrub", 145, 137) {
	if (this != &cp) {
		//TODO
	}
	*this = cp;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) { }

ShrubberyCreationForm& ShrubberyCreationForm::operator=( ShrubberyCreationForm const& ) {
	return *this;
} // TODO: implement

void ShrubberyCreationForm::execute( Bureaucrat const& b ) const {
	Form::execute(b);
	std::ofstream ofs;

	ofs.open(getTarget()+"_shrubbery", std::ofstream::out|std::ofstream::trunc);
	if (ofs.fail()) {
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
	ofs.close();
}
