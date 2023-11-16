/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:55:43 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/14 19:16:47 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void    swap(T & var1, T & var2) {
    T   var3;

    var3 = var1;
    var1 = var2;
    var2 = var3;
}

template    <typename T>
T   min(T var1, T var2) {
    if (var1 < var2)
        return var1;
    return var2;
}

template    <typename T>
T   max(T var1, T var2) {
    if (var1 > var2)
        return var1;
    return var2;
}

#endif