/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:56:39 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/17 20:47:50 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>

struct Data {
    int x;
    int y;
};

class   Serializer {
public:
    Serializer();
    Serializer(const Serializer & src);
    ~Serializer();
    
    Serializer & operator = (const Serializer & rhs);
    
    static  uintptr_t   serialize(Data* ptr);
    static  Data*       deserialize(uintptr_t raw);
};


#endif