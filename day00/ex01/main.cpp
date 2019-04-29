/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callen <callen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:52:30 by callen            #+#    #+#             */
/*   Updated: 2019/04/29 11:52:33 by callen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void usage( void )
{
	std::cout << "CLI Phone Book" << std::endl;
	std::cout << "Standard Commands:" << std::endl;
	std::cout << " ADD" << std::endl;
	std::cout << " SEARCH" << std::endl;
	std::cout << " EXIT" << std::endl << std::endl;
}

int main( void )
{
	Phonebook bookCont;
	std::string ln;

	usage();
	while (1) {
		std::cout << "phonebook$ ";
		if (!std::getline(std::cin, ln)) break;
		bookCont.parse_input(ln);
	}
	return 0;
}
