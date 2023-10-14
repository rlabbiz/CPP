/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:22:37 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/11 10:44:50 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain: Default Constructor called." << '\n'; }

Brain::Brain(const Brain &tmp) {
    std::cout << "Brain: Copy Constructor called." << '\n';
    *this = tmp;
}

Brain::~Brain() { std::cout << "Brain: Destructor called." << '\n'; }

Brain &Brain::operator = (const Brain &next) {
    std::cout << "Brain: Assignment Operator called." << '\n';
    int i = 0;

    while (i < 100){
        this->ideas[i] = next.ideas[i];
        i++;
    }
    return *this;
}