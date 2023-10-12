/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:41:13 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/12 11:49:34 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void){
    ScavTrap clap("first");
    
    clap.showInfo();
    clap.takeDamage(50);
    clap.showInfo();
    clap.attack("attack1");
    clap.showInfo();
    clap.beRepaired(50);
    clap.showInfo();
    clap.guardGate();
}