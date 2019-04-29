/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callen <callen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:12:33 by callen            #+#    #+#             */
/*   Updated: 2019/04/29 11:42:16 by callen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <locale>

//TODO: things

// "Electronic Mail Address: ",
// "Telephonic Address: ",
// "Temporal Lifetime Epoch Address: ",
// "Consumable Matter of Which You Derive Satisfaction: ",
// "Photonic Wavelengths of Undergarments Near the Waist: ",
// "Potentially Damaging Data of Personal Nature Not To Be Used Against You: "


static const std::string __prompts[11] = {
	"First Name: ",
	"Last Name: ",
	"Nickname: ",
	"Login: ",
	"Postal Address: ",
	"E-Mail Address: ",
	"Phone Number: ",
	"Date of Birth: ",
	"Favorite Food Item: ",
	"Underwear Color: ",
	"Darkest Secret: "
};

Phonebook::Phonebook( void ) { _idx = 0; }

void	Phonebook::_add_cnt( void )
{
	std::string ln;

	if (_idx >= 8) {
		std::cout << "Error: Phonebook storage full" << std::endl;
		return;
	} else {
		for (int i = 0; i < 11; i++) {
			std::cout << __prompts[i];
			if (!getline(std::cin, ln)) std::exit(1);
			else {
				switch (i) {
					case  0: _contacts[_idx].firstName      = ln; break;
					case  1: _contacts[_idx].lastName       = ln; break;
					case  2: _contacts[_idx].nickName       = ln; break;
					case  3: _contacts[_idx].login          = ln; break;
					case  4: _contacts[_idx].postalAddress  = ln; break;
					case  5: _contacts[_idx].emailAddress   = ln; break;
					case  6: _contacts[_idx].phoneNumber    = ln; break;
					case  7: _contacts[_idx].birthDate      = ln; break;
					case  8: _contacts[_idx].favoriteMeal   = ln; break;
					case  9: _contacts[_idx].underwearColor = ln; break;
					case 10: _contacts[_idx].darkSecret     = ln; break;
				}
			}
		}
		_idx++;
	}
}

void	Phonebook::_print_cnt( Contact ct ) const
{
	std::cout << "[ First Name      ]: " << ct.firstName << std::endl;
	std::cout << "[ Last Name       ]: " << ct.lastName << std::endl;
	std::cout << "[ Nickname        ]: " << ct.nickName << std::endl;
	std::cout << "[ Login           ]: " << ct.login << std::endl;
	std::cout << "[ Postal Address  ]: " << ct.postalAddress << std::endl;
	std::cout << "[ Email Address   ]: " << ct.emailAddress << std::endl;
	std::cout << "[ Phone Number    ]: " << ct.phoneNumber << std::endl;
	std::cout << "[ Birth Date      ]: " << ct.birthDate << std::endl;
	std::cout << "[ Favorite Meal   ]: " << ct.favoriteMeal << std::endl;
	std::cout << "[ Underwear Color ]: " << ct.underwearColor << std::endl;
	std::cout << "[ Darkest Secret  ]: " << ct.darkSecret << std::endl;
}

static std::string trunc_str( std::string s)
{
	s = s.erase(9, s.length() - 9);
	s += ".";
	return s;
}

void Phonebook::_plonk( void ) const
{
	std::string fN, lN, nN;
	int i;

	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (i = 0; i < _idx; i++) {
		std::cout << "|" << std::setw(10) << i;
		fN = _contacts[i].firstName.length() > 10 ? \
			trunc_str(_contacts[i].firstName) : \
			_contacts[i].firstName;
		std::cout << "|" << std::setw(10) << fN;

		lN = _contacts[i].lastName.length() > 10 ? \
			trunc_str(_contacts[i].lastName) : \
			_contacts[i].lastName;
		std::cout << "|" << std::setw(10) << lN;

		nN = _contacts[i].nickName.length() > 10 ? \
			trunc_str(_contacts[i].nickName) : \
			_contacts[i].nickName;
		std::cout << "|" << std::setw(10) << nN << "|" << std::endl;
	}
}

void Phonebook::_find_cnt( void ) const
{
	std::string ln;
	int i;

	if (_idx > 0) {
		_plonk();
		std::cout << "Enter ID: ";
		if (!std::getline(std::cin, ln)) {
			std::cout << "getline err" << std::endl;
			std::exit(1);
		}
		i = (ln.length() == 1) ? ln[0] - '0' : 9;
		if (!std::cin.good() || (i < 0 || i >= _idx))
			std::cout << "Error: Invalid ID" << std::endl;
		else
			_print_cnt(_contacts[i]);
	} else {
		std::cout << "Error: No Contacts" << std::endl;
	}
}

void Phonebook::parse_input( const std::string& ln )
{
	if (ln == "EXIT") {
		std::exit(0);
	} else {
		if (ln == "ADD")
			_add_cnt();
		else if (ln == "SEARCH")
			_find_cnt();
	}
	return;
}
