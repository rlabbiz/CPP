/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:03:12 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/20 23:47:31 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*Zombie::zombieHorde(int N, std::string name){
	Zombie	*tmp = nullptr;
	int		i = 0;

	if (N <= 0)
		return tmp;
	tmp = new Zombie[N];
	while (i < N){
		tmp[i].setName(name);
		tmp[i].announce();
		i++;
	}
	return tmp;
}
