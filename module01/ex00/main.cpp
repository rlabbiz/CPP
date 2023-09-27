/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:21:53 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/27 15:15:44 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){
	Zombie  *zombie = new Zombie("curr");
	Zombie *test = zombie->newZombie("newZombie");
	
	zombie->announce();
	test->randomChump("randomChump");
	test->announce();
	
	delete zombie;
	delete test;
	return 0;
}
