/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:03:12 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/10 13:02:15 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*Zombie::zombieHorde(int N, std::string name){
	Zombie	*tmp = NULL;
	int		i = 0;

	if (N <= 0)
		return tmp;
	tmp = new Zombie[N];
	while (i < N){
		tmp[i].setName("tmp");
		tmp[i].announce();
		i++;
	}
	return tmp;
}

