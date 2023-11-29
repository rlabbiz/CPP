/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:18:08 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/25 16:18:37 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() {
    MutantStack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.pop();
    MutantStack<int>::iterator it = stack.begin();
    it++;
    std::cout << *it << '\n';
    it--;
    std::cout << *it << '\n';
}
