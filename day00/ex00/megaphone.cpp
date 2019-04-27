/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callen <callen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 12:35:33 by callen            #+#    #+#             */
/*   Updated: 2019/04/26 12:58:34 by callen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void project_thy_voice(int ac, char **av)
{
	for (int i=0; i < ac; i++) {
		for (int j=0; av[i][j]; j++) {
			if (av[i][j] >= 'a' && av[i][j] <= 'z') {
				std::cout << (char)std::toupper(av[i][j]);
			} else {
				std::cout << av[i][j];
			}
		}
	}
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc > 1) {
		project_thy_voice(argc-1, argv+1);
	} else {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	return 0;
}
