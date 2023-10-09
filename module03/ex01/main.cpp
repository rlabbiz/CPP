/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:41:13 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/09 11:26:12 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void){
    ScavTrap clap("first");
    
    clap.showInfo();
    clap.takeDamage(5);
    clap.showInfo();
    clap.attack("attack1");
    clap.showInfo();
    clap.beRepaired(5);
    clap.showInfo();
}