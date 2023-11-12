/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:39:07 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/08 15:49:13 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *  generate(void) {
    int nbr = std::rand() % 3;
    
    if (nbr == 0)
        return new A();
    else if (nbr == 1)
        return new B();
    return new C();
}

void    identify(Base * p) {
    if (dynamic_cast<A *>(p))
        std::cout << "A" << '\n';
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << '\n';
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << '\n';
    else 
        std::cout << "we dont know this type" << '\n';
}

void    identify(Base & p) {
    try {
        A & a = dynamic_cast<A &>(p);
        std::cout << "A" << '\n';
        (void)a;
        return ;
    } catch (std::exception & e) {}
    try {
        B & b = dynamic_cast<B &>(p);
        std::cout << "B" << '\n';
        (void)b;
        return ;
    } catch (std::exception & e) {}
    try {
        C & c = dynamic_cast<C &>(p);
        std::cout << "C" << '\n';
        (void)c;
        return ;
    } catch (std::exception & e) {}
    
    std::cout << "we dont know this type" << '\n';
}