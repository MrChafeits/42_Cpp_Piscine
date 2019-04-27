/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callen <callen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:12:33 by callen            #+#    #+#             */
//   Updated: 2019/04/27 00:47:36 by marvin           ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//TODO: things

Phonebook::Phonebook( void ) {
	_idx = 0;
}

static const std::string __prompts[11] = {
	"First Name: ",
	"Last Name: ",
	"Nickname: ",
	"Login: ",
	"Postal Address: ",
	"Electronic Mail Address: ",
	"Telephonic Address: ",
	"Temporal Epoch Address: ",
	"Consumable Matter of Which Matters Most: ",
	"Photonic Wavelengths of Undergarments Covering the Pelvis: ",
	"Personal Secret of Questionable Origin: "
};

void	Phonebook::_add_cnt( void )
{
	std::string ln;

	if (_idx >= 8) {
		std::cout << "Error: Phonebook storage full" << std::endl;
		return;
	} else {
		for (int i = 0; i < 11; i++) {
			std::cout << __prompts[i];
			if (!getline(std::cin, ln)) std::exit(0);
			else {
				switch (i) {
				case  0: _contacts[_idx].firstName = ln; break;
				case  1: _contacts[_idx].lastName = ln; break;
				case  2: _contacts[_idx].nickName = ln; break;
				case  3: _contacts[_idx].login = ln; break;
				case  4: _contacts[_idx].postalAddress = ln; break;
				case  5: _contacts[_idx].emailAddress = ln; break;
				case  6: _contacts[_idx].phoneNumber = ln; break;
				case  7: _contacts[_idx].birthDate = ln; break;
				case  8: _contacts[_idx].favoriteMeal = ln; break;
				case  9: _contacts[_idx].underwearColor = ln; break;
				case 10: _contacts[_idx].darkSecret = ln; break;
				}
			}
		}
		_idx++;
	}
}

void	Phonebook::_print_cnt( Contact ct ) const
{	
	std::cout << "---- BEGIN CONTACT INFO ----" << std::endl;
	std::cout << "[ First Name      ]: " << ct.firstName << std::endl;
	std::cout << "[ Last Name       ]: " << ct.lastName << std::endl;
	std::cout << "[ Nickname        ]: " << ct.nickName << std::endl;
	std::cout << "[ Login           ]: " << ct.login << std::endl;
	std::cout << "[ Postal Address  ]: " << ct.postalAddress << std::endl;
	std::cout << "[ Email Address   ]: " << ct.emailAddress << std::endl;
	std::cout << "[ Birth Date      ]: " << ct.birthDate << std::endl;
	std::cout << "[ Favorite Meal   ]: " << ct.favoriteMeal << std::endl;
	std::cout << "[ Underwear Color ]: " << ct.underwearColor << std::endl;
	std::cout << "[ Dark Secret     ]: " << ct.darkSecret << std::endl;
	std::cout << "---- END CONTACT INFO ----" << std::endl;
}

void	print_n_spaces( int n )
{
	if (n < 0) return;
	for (; n--;) std::cout << " ";
}

#define MAX(a,b) ((a)>(b)?(a):(b))

void	Phonebook::_dump_all_cnt( void ) const
{
	std::string fN = "First Name", lN = "Last Name", nN = "\"Nickname\"";
	unsigned long fNpad = 16, lNpad = 16, nNpad = 16;
	int i;

	for (i = 0; i < _idx; i++) {
		fNpad = MAX(_contacts[i].firstName.length(), fNpad);
		lNpad = MAX(_contacts[i].lastName.length(), lNpad);
		nNpad = MAX(_contacts[i].nickName.length(), nNpad);
	}
	std::cout << "# ";
	std::cout << fN; print_n_spaces(fNpad - fN.length());
	std::cout << nN; print_n_spaces(nNpad - nN.length());
	std::cout << lN; print_n_spaces(lNpad - lN.length());
	std::cout << std::endl;
	for (i = 0; i < _idx; i++) {
		std::cout << i << " " << _contacts[i].firstName;
		print_n_spaces(fNpad - _contacts[i].firstName.length());
		std::cout << "\"" << _contacts[i].nickName << "\"";
		print_n_spaces(nNpad - (_contacts[i].nickName.length() + 2));
		std::cout << _contacts[i].lastName;
		print_n_spaces(lNpad - _contacts[i].lastName.length());
		std::cout << std::endl;
	}
}

static std::string reduce_length_strong( std::string s)
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
			reduce_length_strong(_contacts[i].firstName) : \
			_contacts[i].firstName;
		std::cout << "|" << std::setw(10) << fN;

		lN = _contacts[i].lastName.length() > 10 ? \
			reduce_length_strong(_contacts[i].lastName) : \
			_contacts[i].lastName;
		std::cout << "|" << std::setw(10) << lN;

		nN = _contacts[i].nickName.length() > 10 ? \
			reduce_length_strong(_contacts[i].nickName) : \
			_contacts[i].nickName;
		std::cout << "|" << std::setw(10) << nN << "|" << std::endl;
	}
}

void Phonebook::_find_cnt( void ) const
{
	std::string ln;
	int i;

	if (!_idx) {
		std::cout << "Error: No Contacts" << std::endl;
		return;
	}
	_plonk();
	std::cout << "Enter ID: ";
	std::cin >> i; std::cout << std::endl;
	if (!std::cin.good() || (i < 0 || i >= _idx)) {
		std::exit(0);
	} else {
		_print_cnt(_contacts[i]);
	}
}

void Phonebook::parse_input(const std::string& ln)
{
	if (ln == "EXIT") std::exit(0);
	else if (ln == "ADD") _add_cnt();
	else if (ln == "SEARCH") _find_cnt();
}

#undef MAX
