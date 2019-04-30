/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callen <callen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:10:25 by callen            #+#    #+#             */
/*   Updated: 2019/04/29 17:10:46 by callen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include <iostream>
#include <string>
#include "Zombie.hpp"

class ZombieEvent {

public:
	ZombieEvent( void );
	~ZombieEvent( void );
	static Zombie *newZombie( std::string n );
	static Zombie *newZombie( void );
	static Zombie *randomChump( void );
	static void setZombieType( std::string t );
	static std::string getZombieType( void );

private:
	static std::string _zombieType;
	static std::random_device rd;

};

void a();

#endif /* ZOMBIEEVENT_HPP */
