/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:24:16 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/28 13:29:20 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>

int main(void) {
    const int a = 1;
    const int *b = &a;
    int *c = const_cast<int*>(b);
    *c = 8;
    
    std::cout << c << '\n'; // should display eight
    std::cout << &a << '\n'; // should display one
    
    // delete c;
    return 0;   
}
