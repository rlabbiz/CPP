/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:48:05 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/15 15:20:34 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat: Default constructor called." << '\n';
    this->brain = NULL;
}

Cat::Cat(std::string str) : Animal(str) {
    std::cout << "Cat: constructor called." << '\n';
    this->brain = new Brain();
}

Cat::Cat(const Cat& tmp){
    std::cout << "Cat: Copy constructor called." << '\n';
    *this = tmp;
}

Cat::~Cat() {
    std::cout << "Cat: Destructor called." << '\n';
    delete this->brain;
}

Cat& Cat::operator = (const Cat& next) {
    std::cout << "Cat: Copy assignment operator called." << '\n';
    if (this == &next)
        return *this;
    this->type = next.type;
    return *this;
}

void    Cat::makeSound(void) const {
    std::cout << "Cat: Meow" << '\n';
}
