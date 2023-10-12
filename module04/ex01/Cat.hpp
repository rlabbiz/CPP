/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:48:07 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/11 11:02:05 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
private:
    Brain *brain;
public:
    Cat();
    Cat(std::string str);
    Cat(const Cat& tmp);
    ~Cat();

    Cat& operator = (const Cat& next);
    
    void    makeSound(void) const;

};

#endif