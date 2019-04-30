/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callen <callen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:05:24 by callen            #+#    #+#             */
/*   Updated: 2019/04/29 17:05:53 by callen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>
#include <string>

Pony::Pony( void )
{
	// std::cout << "constructor (" << this << ")" << std::endl;
	return;
}

Pony::Pony( Pony const &cp )
{
	// std::cout << "copy constructor (" << this << ")" << std::endl;
	*this = cp;
	return;
}

Pony::~Pony( void )
{
	// std::cout << "destructor (" << this << ")" << std::endl;
	_age.clear();
	_coat.clear();
	_mane.clear();
	_name.clear();
	// delete this;
	return;
}

Pony& Pony::operator=( Pony const& )	// TODO: implement
{
	// std::cout << "= operator overload (" << this << ")" << std::endl;
	return *this;
}

void Pony::setAge( std::string s ) { this->_age = s; }

void Pony::setCoat( std::string s ) { this->_coat = s; }

void Pony::setMane( std::string s ) { this->_mane = s; }

void Pony::setName( std::string s ) { this->_name = s; }

std::string Pony::getAge( void ) const { return this->_age; }

std::string Pony::getCoat( void ) const { return this->_coat; }

std::string Pony::getMane( void ) const { return this->_mane; }

std::string Pony::getName( void ) const { return this->_name; }
