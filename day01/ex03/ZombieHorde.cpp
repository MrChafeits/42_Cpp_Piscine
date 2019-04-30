/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callen <callen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:13:07 by callen            #+#    #+#             */
/*   Updated: 2019/04/29 17:13:51 by callen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde( void ): _size(8)
{
	this->_horde = new Zombie[_size];
}

ZombieHorde::ZombieHorde( int n ): _size(n)
{
	this->_horde = new Zombie[_size];
	for (int i = 0; i < _size; i++) {
		this->_horde[i].setType("Horde");
	}
}

ZombieHorde::ZombieHorde( ZombieHorde const &cp ) { *this = cp; }

ZombieHorde::~ZombieHorde( void ) { delete[] this->_horde; }

ZombieHorde& ZombieHorde::operator=( ZombieHorde const& ) { return *this; }	// TODO: implement

void ZombieHorde::announce( void ) const
{
	for (int i = 0; i < this->_size; i++)
		this->_horde[i].announce();
}
