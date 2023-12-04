/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:05:20 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/12/04 12:28:37 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() { }
RPN::RPN(const RPN & src) { *this = src; }
RPN::~RPN() { }
RPN &   RPN::operator = (const RPN & rhs) { (void)rhs; return *this; }

bool    RPN::isNumber(char c) {
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

int  RPN::hadleSymbol(int nbr1, int nbr2, char op) {
    switch (op)
    {
        case '-':
            return nbr1 - nbr2;
        case '+':
            return nbr1 + nbr2;
        case '*':
            return nbr1 * nbr2;
        case '/':
            return nbr1 / nbr2;
        default:
            std::cerr << "Error" << '\n';
            exit(1);
    }
}

bool    RPN::isValidOp(char c) {
    return (c == '-' || c == '+' || c == '*' || c == '/');
}

int  RPN::calReversePolishNotation(const char * str) {
    std::stack<int> stack;

    int nbr1;
    int nbr2;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isNumber(str[i]))
            stack.push(str[i] - 48);
        else if (isValidOp(str[i]) && stack.size() > 1) {
            nbr2 = stack.top();
            stack.pop();
            nbr1 = stack.top();
            stack.pop();
            stack.push(hadleSymbol(nbr1, nbr2, str[i]));
        } else if (str[i] == ' ') {}
        else {
            std::cerr << "Error" << '\n';
            exit(1);
        }
    }
    if (stack.size() != 1) {
        std::cerr << "Error" << '\n';
        exit(1);
    }
    return stack.top();
}
