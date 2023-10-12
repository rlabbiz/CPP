/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:48:10 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/12 12:46:51 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog: Default constructor called." << '\n';
    this->brain = nullptr;
}

Dog::Dog(std::string str) : Animal(str) {
    std::cout << "Dog: constructor called." << '\n';
    this->brain = new Brain();
}

Dog::Dog(const Dog& tmp) : Animal(tmp){
    std::cout << "Dog: Copy constructor called." << '\n';
}

Dog::~Dog() {
    std::cout << "Dog: Destructor called." << '\n';
    delete this->brain;
}

Dog& Dog::operator = (const Dog& next) {
    std::cout << "Dog: Copy assignment operator called." << '\n';
    this->type = next.type;
    return *this;
}

void    Dog::makeSound(void) const {
    std::cout << "Dog: Woof" << '\n';
}
