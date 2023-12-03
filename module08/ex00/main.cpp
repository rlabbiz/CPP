/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:25:58 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/12/02 22:57:30 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"

int main(void) {
    std::vector<int> vector;

    vector.push_back(1);
    vector.push_back(2);
    try {
        std::cout << easyFind(vector, 4) << '\n';
    } catch (std::exception & e) {
        std::cout << e.what() << '\n';
    }
}