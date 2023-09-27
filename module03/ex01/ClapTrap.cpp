/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:41:04 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/26 15:06:44 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(std::string str) : name(str) {}

ClapTrap::~ClapTrap() {}

ClapTrap&    ClapTrap::operator = (ClapTrap &next) {
    name            = next.name;
    hitPoint        = next.hitPoint;
    energyPoint     = next.energyPoint;
    attackDamage    = next.attackDamage;
    return (*this);
}
