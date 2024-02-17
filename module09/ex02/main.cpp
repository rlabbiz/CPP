/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:51:35 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/12/15 10:52:30 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error" << '\n';
        exit(1);
    }
    
    std::list<int>  list = getSequence(av);
    std::cout << "Before:" << '\t';
    for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
        std::cout << *it << " ";
    std::cout << '\n';
    
    SortVector     vector(list.begin(), list.end());
    std::cout << "After:" << '\t';
    for (std::vector<int>::iterator it = vector.vector().begin(); it != vector.vector().end(); it++)
        std::cout << *it << ' ';
    std::cout << '\n';
    std::cout << "Time to process a range of " << list.size() << " elements with " << "std::vector: " << vector.time() << " us" <<'\n';
    
    SortDeque      deque(list.begin(), list.end());
    std::cout << "Time to process a range of " << list.size() << " elements with " << "std::deque: " << deque.time() << " us" <<'\n';
}