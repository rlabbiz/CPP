/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:56:36 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/17 20:51:51 by rlabbiz          ###   ########.fr       */
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
    
    return 0;
}