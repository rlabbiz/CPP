/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:05:26 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/12/04 12:35:09 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
public:
    RPN();
    RPN(const RPN & src);
    ~RPN();

    RPN &   operator = (const RPN & rhs);
    
    static bool isNumber(char c);
    static bool isValidOp(char c);
    static int  hadleSymbol(int nbr1, int nbr2, char op);
    static int  calReversePolishNotation(const char * str);
};

#endif