/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:25:56 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/12/02 23:03:25 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <exception>


template <typename T> int  easyFind(T & container, int element) {
    typename T::iterator    it;

    it = std::find(container.begin(), container.end(), element);
    if (it == container.end())
        throw std::out_of_range("Element Not Found.");
    return *it;
}

#endif