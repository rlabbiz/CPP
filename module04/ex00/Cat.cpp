/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:48:05 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/09 17:40:07 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat: Default constructor called." << '\n';
}

Cat::Cat(std::string str) : Animal(str) {
    std::cout << "Cat: constructor called." << '\n';
}

Cat::Cat(const Cat& tmp) : Animal(tmp){
    std::cout << "Cat: Copy constructor called." << '\n';
}

Cat::~Cat() {
    std::cout << "Cat: Destructor called." << '\n';
}

Cat& Cat::operator = (const Cat& next) {
    std::cout << "Cat: Copy assignment operator called." << '\n';
    this->type = next.type;
    return *this;
}

void    Cat::makeSound(void) const {
    std::cout << "hello" << '\n';
}
