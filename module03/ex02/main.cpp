/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:41:13 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/09 12:44:33 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void){
    FragTrap clap("first");
    
    clap.showInfo();
    clap.takeDamage(5);
    clap.showInfo();
    clap.attack("attack1");
    clap.showInfo();
    clap.beRepaired(5);
    clap.showInfo();
}