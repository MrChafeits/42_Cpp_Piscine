/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callen <callen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:10:54 by callen            #+#    #+#             */
/*   Updated: 2019/04/29 17:10:55 by callen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main( void )
{
	Zombie nick = Zombie("Nick");
	Zombie *z1 = ZombieEvent::randomChump();

	ZombieEvent::setZombieType("Spinning");
	Zombie *z2 = ZombieEvent::randomChump();
	delete z1;
	delete z2;
	nick.announce();
}
