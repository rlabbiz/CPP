/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:24:26 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/27 17:15:40 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
public:
    ScalarConverter();
    ScalarConverter(ScalarConverter const & src);
    ~ScalarConverter();
    
    ScalarConverter & operator = (ScalarConverter const & rhs);
    
    void    print(const char * str);

    char    convertToChar(const char * str);
    int     convertToInt(const char * str);
    float   convertToFloat(const char * str);
    double  convertToDouble(const char * str);
};

#endif