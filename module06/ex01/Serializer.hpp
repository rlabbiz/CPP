/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:56:39 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/28 12:46:13 by rlabbiz          ###   ########.fr       */
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
private:
    Serializer();
    ~Serializer();
public:
    static  uintptr_t   serialize(Data* ptr);
    static  Data*       deserialize(uintptr_t raw);
};


#endif