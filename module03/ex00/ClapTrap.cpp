/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:41:04 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/02 15:41:24 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "Defualt constructor called" << '\n';
    hitPoint        = 10;
    energyPoint     = 10;
    attackDamage    = 0;
}

ClapTrap::ClapTrap(std::string str) : name(str) {
    std::cout << "Defualt constructor called" << '\n';
    hitPoint        = 10;
    energyPoint     = 10;
    attackDamage    = 0;
}

ClapTrap::ClapTrap(const ClapTrap& tmp){
    std::cout << "Copy constructor called" << '\n';
    (*this) = tmp;
}

ClapTrap::~ClapTrap() { std::cout << "Destructor called" << '\n'; }

ClapTrap&    ClapTrap::operator = (const ClapTrap &next) {
    std::cout << "Copy assignment operator called" << '\n';
    name            = next.name;
    hitPoint        = next.hitPoint;
    energyPoint     = next.energyPoint;
    attackDamage    = next.attackDamage;
    return (*this);
}

int    ClapTrap::getHitPoint(void) const { return (hitPoint); }
int    ClapTrap::getEnergyPoint(void) const { return (energyPoint); }
int    ClapTrap::getAttackDamage(void) const { return (attackDamage); }

void    ClapTrap::setHitPoint(int amout) { hitPoint = amout; }
void    ClapTrap::setEnergyPoint(int amout) { energyPoint = amout; }
void    ClapTrap::setAttackDamage(int amout) { attackDamage = amout; }

void    ClapTrap::attack(const std::string& target) {
    if (hitPoint <= 0 || energyPoint <= 0){
        std::cout << "Can't do anything, No points left." << '\n';
        return ;
    }
    hitPoint -= attackDamage;
    energyPoint--;
    std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage!" << '\n';
}

void    ClapTrap::takeDamage(unsigned int amout) {
    if (hitPoint <= 0 || energyPoint <= 0){
        std::cout << "Can't do anything, No points left." << '\n';
        return ;
    }
    attackDamage = amout;
    std::cout << "ClapTrap " << name << " take damage " << amout << "\n";
}

void    ClapTrap::beRepaired(unsigned int amout) {
    if (hitPoint <= 0 || energyPoint <= 0){
        std::cout << "Can't do anything, No points left." << '\n';
        return ;
    }
    hitPoint += amout;
    energyPoint--;
    std::cout << "ClapTrap " << name << " be repaired " << amout << "\n";
}

void    ClapTrap::showInfo(void) {
    std::cout << "-----------------------------" << '\n';
    std::cout << "Name: " << name << '\n';
    std::cout << "Hit Point: " << hitPoint << '\n';
    std::cout << "Energy Point: " << energyPoint << '\n';
    std::cout << "Attack Damage: " << attackDamage << '\n';
    std::cout << "-----------------------------" << '\n';
}
