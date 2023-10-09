/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:55:52 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/09 12:35:01 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap: Defualt constructor called." << '\n';
    hitPoint        = 100;
    energyPoint     = 50;
    attackDamage    = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap: constructor called." << '\n';
    hitPoint        = 100;
    energyPoint     = 50;
    attackDamage    = 20;
}

ScavTrap::ScavTrap(const ScavTrap &tmp) {
    std::cout << "ScavTrap: copy constructor called." << '\n';
    *this = tmp;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap: destructor called." << '\n'; }

ScavTrap&   ScavTrap::operator = (const ScavTrap &next) {
    std::cout << "ScavTrap: copy assimgnet operator constructor called." << '\n';
    this->attackDamage = next.attackDamage;
    this->energyPoint = next.energyPoint;
    this->hitPoint = next.hitPoint;
    return (*this);
}

void    ScavTrap::guardGate() {
    std::cout << "ScavTrap : " << this->name << " is now in Gate keeper mode" << '\n';
}