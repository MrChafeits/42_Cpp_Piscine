/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callen <callen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:13:23 by callen            #+#    #+#             */
/*   Updated: 2019/04/29 17:13:29 by callen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ZombieHorde.hpp"

int main(int ac, char **av)
{
	ZombieHorde *chonk = new ZombieHorde(16);

	std::cout << "[Chonk Horde]" << std::endl;
	chonk->announce();
	delete chonk;

	ZombieHorde smol;
	std::cout << "[Smol Horde]" << std::endl;
	smol.announce();

	if (ac > 1 && !std::strncmp(av[1],"leak", 8)) while (1);
	return 0;
}
