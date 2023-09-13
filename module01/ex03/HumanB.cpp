/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:49:27 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/12 17:10:54 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string str) : name(str), wpn(nullptr) {}

HumanB::~HumanB(void) {}

void	HumanB::setWeapon(Weapon &wp) {
	wpn = &wp;
}

void	HumanB::attack(void){
	std::cout << this->name << " attacks with their " << this->wpn->getType() << '\n';
}
