/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:21:53 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/24 00:29:55 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){

	// Zombie  *zombie = new Zombie("curr");
	
	// zombie->announce();
	
	Zombie *tmp = zombieHorde(3, "tmp");
	
	// delete zombie;
	delete[] tmp;

	return 0;
}
