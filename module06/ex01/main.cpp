/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:56:36 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/13 09:59:36 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

uintptr_t   serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data*       deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}

int main(void) {
    Data *data = new Data();
    data->x = 15;
    data->y = 25;
    
    Data *newData = deserialize(serialize(data));
    
    std::cout << newData->x << '\n';
    std::cout << newData->y << '\n';
    std::cout << data << '\n';
    std::cout << newData << '\n';
    
    return 0;
}