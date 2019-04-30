/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callen <callen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:09:48 by callen            #+#    #+#             */
/*   Updated: 2019/04/29 17:09:56 by callen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <random>
#include <string>

class Zombie {

public:
	Zombie( void );
	Zombie( std::string n );
	Zombie( std::string n, std::string t );
	~Zombie( void );

	void announce( void ) const;

	void setName( std::string s );
	void setType( std::string s );

	std::string getName( void ) const;
	std::string getType( void ) const;

private:
	std::string _name;
	std::string _type;

};

#endif /* ZOMBIE_HPP */
