/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:48:13 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/15 15:11:30 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
    
    int     i = 0;
    int     objLen = 6;
    Animal  *animals[objLen];
    
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
