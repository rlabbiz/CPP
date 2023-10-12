/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:55:52 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/11 15:12:03 by rlabbiz          ###   ########.fr       */
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
    if (this == &next)
        return *this;
    this->attackDamage = next.attackDamage;
    this->energyPoint = next.energyPoint;
    this->hitPoint = next.hitPoint;
    return (*this);
}

void    ScavTrap::attack(const std::string& target) {
    std::cout << "ScavTrap: " << name << " attacks " << target << " causing " << attackDamage << " points of damage!" << '\n';
    if (hitPoint <= 0 || energyPoint <= 0){
        std::cout << "ClapTrap: Can't do anything, No points left." << '\n';
        return ;
    }
    energyPoint--;
}

void    ScavTrap::guardGate() {
    std::cout << "ScavTrap : " << this->name << " is now in Gate keeper mode" << '\n';
}