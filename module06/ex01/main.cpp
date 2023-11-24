/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:56:36 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/22 11:27:41 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
    Serializer serializer;
    Data *data = new Data();
    data->x = 15;
    data->y = 25;
    
    Data *newData = serializer.deserialize(serializer.serialize(data));
    
    std::cout << newData->x << '\n';
    std::cout << newData->y << '\n';
    std::cout << data << '\n';
    std::cout << newData << '\n';
    
    delete data;
    return 0;
}