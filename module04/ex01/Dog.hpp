/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:48:23 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/12 14:06:56 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
private:
    Brain *brain;
public:
    Dog();
    Dog(std::string str);
    Dog(const Dog& tmp);
    ~Dog(); 

    Dog& operator = (const Dog& next);

    void    makeSound(void) const;
};

#endif