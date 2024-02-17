/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:18:08 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/12/03 20:41:41 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() {
    MutantStack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); it++) {
        std::cout << *it << '\n';
    }
}