/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:48:13 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/12 13:43:55 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
    
    int     i = 0;
    int     objLen = 4;
    Animal  **animals = new Animal*[objLen];
    
    while (i < objLen / 2) {
        animals[i] = new Cat("Cat");
        i++;
    }
    
    while (i < objLen) {
        animals[i] = new Dog("Dog");
        i++;
    }
    
    i = 0;

    while (i < objLen) {
        animals[i]->makeSound();
        i++;
    }
    
    i = 0;
    
    while (i < objLen) {
        delete animals[i];
        i++;
    }
    
    delete[] animals;
    return 0;
}

// int main()
// {
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     delete j;//should not create a leak
//     delete i;
    
//     return 0;
// }
