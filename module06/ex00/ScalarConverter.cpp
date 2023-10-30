/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:24:23 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/28 12:17:20 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const & src) { (void)src; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter & ScalarConverter::operator = (ScalarConverter const & rhs) { (void)rhs; return *this; }

void    ScalarConverter::print(const char * str) {
    (void)str;
}

