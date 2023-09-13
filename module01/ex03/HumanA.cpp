/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:43:51 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/12 17:02:56 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon &wp) : name(str), wpn(wp) {}

HumanA::~HumanA(void) {}

void	HumanA::attack(void){
	std::cout << this->name << " attacks with their " << this->wpn.getType() << '\n';
}

void	HumanA::setWeapon(Weapon &wp){
	this->wpn = wp;
}
