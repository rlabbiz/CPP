/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:51:46 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/08 15:36:22 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <exception>

class Base {
public:
    virtual ~Base() {}
};

class A : public Base { };

class B : public Base { };

class C : public Base { };

Base*   generate(void);

void    identify(Base* p);

void    identify(Base& p);

#endif