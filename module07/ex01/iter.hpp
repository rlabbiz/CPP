/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:56:01 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/12/01 14:28:02 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void    dispaly(T nbr) {
    std::cout << nbr << '\n';
}

template <typename T, typename U> void  iter(T *array, int len, void (*f)(U)) {
    for (int i = 0; i < len; i++) {
        f(array[i]);
    }
}

#endif