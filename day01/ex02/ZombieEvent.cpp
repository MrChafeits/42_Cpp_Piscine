/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callen <callen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:10:08 by callen            #+#    #+#             */
/*   Updated: 2019/04/29 17:10:09 by callen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

std::string ZombieEvent::_zombieType = "Regular";

void ZombieEvent::setZombieType( std::string t ) { _zombieType = t; }

Zombie *ZombieEvent::newZombie( std::string n )
{
	Zombie *z = new Zombie(n);
	z->setType(_zombieType);
	return z;
}

Zombie *ZombieEvent::newZombie( void )
{
	Zombie *z = new Zombie();
	z->setType(_zombieType);
	return z;
}

Zombie *ZombieEvent::randomChump( void )
{
	Zombie *z = newZombie();
	z->announce();
	return z;
}

