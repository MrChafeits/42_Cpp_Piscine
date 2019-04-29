/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callen <callen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:15:22 by callen            #+#    #+#             */
/*   Updated: 2019/04/29 11:52:18 by callen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Phonebook {

private:
	class Contact {

	public:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string login;
		std::string postalAddress;
		std::string emailAddress;
		std::string phoneNumber;
		std::string birthDate;
		std::string favoriteMeal;
		std::string underwearColor;
		std::string darkSecret;
	};

	Contact _contacts[8];
	int		_idx;

	void	_plonk( void ) const;
	void	_add_cnt( void );
	void	_find_cnt( void ) const;
	void	_print_cnt( Contact ct ) const;

public:
	Phonebook( void );
	void	parse_input( const std::string& input );
};

#endif /* PHONEBOOK_HPP */
