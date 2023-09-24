/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:03:12 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/24 00:32:25 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name){
	Zombie	*tmp = nullptr;
	int		i = 0;

	tmp = new Zombie[N];
	while (i < N){
		tmp[i].setName(name);
		tmp[i].announce();
		i++;
	}
	return tmp;
}
