/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:48:02 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/09 17:48:38 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal: Defualt constructor called." << '\n';
}

Animal::Animal(std::string str) : type(str) {
    std::cout << "Animal: constructor called." << '\n';
}

Animal::Animal(const Animal& tmp) {
    std::cout << "Animal: Copy constructor called." << '\n';
    *this = tmp;
}

Animal::~Animal() {
    std::cout << "Animal: Destructor called." << '\n';
}

Animal& Animal::operator = (const Animal& next) {
    std::cout << "Animal: Copy assignment operator called." << '\n';
    this->type = next.type;
    return *this;
}

std::string Animal::getType(void) const { return type; }

void    Animal::makeSound(void) const { return ; }
