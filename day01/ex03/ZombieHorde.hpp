/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callen <callen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:13:15 by callen            #+#    #+#             */
/*   Updated: 2019/04/29 17:13:16 by callen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include <iostream>
#include <string>
#include "Zombie.hpp"

class ZombieHorde {

public:
	ZombieHorde( void );
	ZombieHorde( int n );
	ZombieHorde( ZombieHorde const & );
	~ZombieHorde( void );
	ZombieHorde& operator=( ZombieHorde const& );

	void announce( void ) const;

private:
	Zombie *_horde;
	int _size;
};

#endif /* ZOMBIEHORDE_HPP */
