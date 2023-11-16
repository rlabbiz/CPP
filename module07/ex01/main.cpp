/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:55:59 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/15 14:36:50 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void) {
    char *str = new char[3];

    str[0] = 'a';
    str[1] = 'b';
    str[2] = 'c';
    
    iter<char >(str, 3, print<char >);

    delete[] str;
}