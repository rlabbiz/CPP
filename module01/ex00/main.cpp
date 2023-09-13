/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:21:53 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/10 10:38:36 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){

	Zombie  *zombie = new Zombie("curr");
	zombie->announce();
	Zombie *test = zombie->newZombie("newZombie");
	test->randomChump("randomChump");

	test->announce();
	delete zombie;
	delete test;
	return 0;
}
