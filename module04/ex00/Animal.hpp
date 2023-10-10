/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:47:59 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/09 17:51:26 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
    std::string type;
public:
    Animal();
    Animal(std::string str);
    Animal(const Animal& tmp);
    virtual ~Animal();
    
    Animal& operator = (const Animal& next);

    std::string getType(void) const;

    virtual void makeSound(void) const;
};

#endif