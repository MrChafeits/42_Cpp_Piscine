#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: "
				  << *av
				  << " [file] [search_str] [replace_str]"
				  << std::endl;
		return 1;
	}
	std::ifstream ifs(av[1]);
	std::string s = static_cast<std::string>(av[2]);
	std::string r = static_cast<std::string>(av[3]);
	if (s.length() < 1)
	{
		std::cerr << "Error: invalid search string" << std::endl;
		return (1);
	}
	std::ofstream ofs(static_cast<std::string>(av[1]).append(".replace"));
	std::string readout;
	while (getline(ifs, readout))
	{
		for (int i = 0; readout[i]; i++)
		{
			if (readout.substr(i, s.length()) == s)
			{
				ofs << r;
				i += s.length() - 1;
			}
			else
				ofs << static_cast<char>(readout[i]);
		}
		ofs << std::endl;
	}
}
