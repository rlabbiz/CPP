/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:41:04 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/11 12:58:30 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "ClapTrap: Defualt constructor called" << '\n';
    hitPoint        = 10;
    energyPoint     = 10;
    attackDamage    = 0;
}

ClapTrap::ClapTrap(std::string str) : name(str) {
    std::cout << "ClapTrap: constructor called" << '\n';
    hitPoint        = 10;
    energyPoint     = 10;
    attackDamage    = 0;
}

ClapTrap::ClapTrap(const ClapTrap& tmp){
    std::cout << "ClapTrap: Copy constructor called" << '\n';
    (*this) = tmp;
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap: Destructor called" << '\n'; }

ClapTrap&    ClapTrap::operator = (const ClapTrap &next) {
    std::cout << "ClapTrap: Copy assignment operator called" << '\n';
    if (this == &next)
        return *this;
    name            = next.name;
    hitPoint        = next.hitPoint;
    energyPoint     = next.energyPoint;
    attackDamage    = next.attackDamage;
    return (*this);
}

void    ClapTrap::attack(const std::string& target) {
    std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage!" << '\n';
    if (hitPoint <= 0 || energyPoint <= 0){
        std::cout << "ClapTrap: Can't do anything, No points left." << '\n';
        return ;
    }
    energyPoint--;
}

void    ClapTrap::takeDamage(unsigned int amout) {
    if (hitPoint <= 0 || energyPoint <= 0){
        std::cout << "ClapTrap: Can't do anything, No points left." << '\n';
        return ;
    }
    std::cout << "ClapTrap " << name << " take damage " << amout << "\n";
    hitPoint -= amout;
}

void    ClapTrap::beRepaired(unsigned int amout) {
    if (hitPoint <= 0 || energyPoint <= 0){
        std::cout << "ClapTrap: Can't do anything, No points left." << '\n';
        return ;
    }
    std::cout << "ClapTrap " << name << " be repaired " << amout << "\n";
    hitPoint += amout;
    energyPoint--;
}

void    ClapTrap::showInfo(void) {
    std::cout << "-----------------------------" << '\n';
    std::cout << "Name: " << name << '\n';
    std::cout << "Hit Point: " << hitPoint << '\n';
    std::cout << "Energy Point: " << energyPoint << '\n';
    std::cout << "Attack Damage: " << attackDamage << '\n';
    std::cout << "-----------------------------" << '\n';
}
