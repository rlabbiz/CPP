/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:05:16 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/12/04 09:48:29 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
    
    if (ac != 2) {
        std::cout << "Usage: ./RPN \"reverse polish notation\" " << '\n';
        std::cout << "\tplease one argument after program name." << '\n';
        return 1;
    }
    std::cout << RPN::calReversePolishNotation(av[1]) << '\n';
    return 0;
}