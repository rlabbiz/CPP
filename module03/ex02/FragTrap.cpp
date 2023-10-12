/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:11:53 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/11 12:59:07 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "FragTrap: Defualt constructor called." << '\n';
    this->hitPoint      = 100;
    this->energyPoint   = 100;
    this->attackDamage  = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap: constructor called." << '\n';
    this->hitPoint      = 100;
    this->energyPoint   = 100;
    this->attackDamage  = 30;
}

FragTrap::FragTrap(const FragTrap& tmp) : ClapTrap(tmp) {
    std::cout << "FragTrap: Copy constructor called." << '\n';
    *this = tmp;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap: destructor called." << '\n';
}

FragTrap&   FragTrap::operator = (const FragTrap& next) {
    std::cout << "FragTrap: copy assimgmnet called." << '\n';
    if (this == &next)
        return *this;
    this->name          = next.name;
    this->hitPoint      = next.hitPoint;
    this->energyPoint   = next.energyPoint;
    this->attackDamage  = next.attackDamage;
    
    return *this;
}
