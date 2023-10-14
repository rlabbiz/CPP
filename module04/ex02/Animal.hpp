/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:47:59 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/14 14:57:12 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "Brain.hpp"

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

    virtual void makeSound(void) const = 0;
};

#endif