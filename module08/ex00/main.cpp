/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:25:58 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/17 12:49:11 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"

int main(void) {
    std::vector<int> array;

    array.push_back(9);
    array.push_back(8);
    array.push_back(0);
    array.push_back(6);
    array.push_back(-1);
    array.push_back(-1);
    array.push_back(-1);
    array.push_back(-1);

    // std::sort(&array.front(), &array.back() + 1);

    // for (unsigned long i = 0; i < array.size(); i++) {
    //     std::cout << array[i] << '\n';
    // }

    std::cout << array.get_allocator() << '\n';

    
}