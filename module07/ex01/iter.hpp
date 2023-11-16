/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:56:01 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/15 13:26:32 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void    print(T nbr) {
    std::cout << nbr << '\n';
}

template <typename T> void  iter(T *array, int len, void (*f)(T)) {
    for (int i = 0; i < len; i++) {
        f(array[i]);
    }
}

#endif