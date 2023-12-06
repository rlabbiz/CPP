/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:51:35 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/12/04 21:46:54 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error" << '\n';
        exit(1);
    }
    
    std::list<int>  list = getSequence(av);
    SortVector      vector(list.begin(), list.end());
    
    (void)vector;
}