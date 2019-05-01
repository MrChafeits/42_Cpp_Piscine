/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callen <callen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:09:36 by callen            #+#    #+#             */
/*   Updated: 2019/04/29 17:09:37 by callen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string _ztypes[10] = {
	"Walker",
	"Shambler",
	"Crawler",
	"Spitter",
	"Jockey",
	"Smoker",
	"Charger",
	"Hunter",
	"Witch",
	"Tank"
};

std::string _aup = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string _alp = "abcdefghijklmnopqrstuvwxyz";

Zombie::Zombie( std::string n, std::string t )
{
	this->_name = n;
	this->_type = t;
}

Zombie::Zombie( std::string n )
{
	this->_name = n;
	this->_type = _ztypes[rand() % 10];
}

Zombie::Zombie( void )
{
	this->_type = _ztypes[rand() % 10];
	this->_name.push_back(static_cast<char>(std::toupper(_alp[rand()%26])));
	for (unsigned int len = 4+rand()%8; len; len--)
		this->_name.push_back(_alp[rand()%26]);
}

Zombie::~Zombie( void ) { }
void Zombie::setName( std::string s ) { this->_name = s; }
void Zombie::setType( std::string s ) { this->_type = s; }

std::string Zombie::getName( void ) const { return this->_name; }
std::string Zombie::getType( void ) const { return this->_type; }

void Zombie::announce( void ) const
{
	std::cout << "<" << this->_name
			  << " (" << this->_type
			  << ")> Braiiiiiiinnssss..." << std::endl;
}
