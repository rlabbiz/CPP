/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:24:26 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/29 21:01:17 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <cctype>
#include <climits>
#include <cstdlib>

typedef enum e_type {
    CHAR,
    INT,
    NOT_INT,
    FLOAT,ef enum e_psude {
    PLUS_INFF,
    INFF,
    NANF,
    PLUS_INF,
    INF,
    NAN,
    NONE_PSUDE,
    DOUBLE,
    NONE_TYPE,
}   n_type;

typed
}   n_psude;

typedef struct s_var {
    bool    _impossible;
    bool    _intPossible;
    n_type  _type;
    n_psude _psude;
    char    _char;
    long    _int;
    float   _float;
    double  _double;
}   t_var;

class ScalarConverter {
private:
    static void         findType(const std::string & str, t_var & var);
    static bool         findPsude(const std::string & str, t_var & var);
    static void         checkInt(std::string str, t_var & var);
    static std::string  getPsudeType(n_psude type, int var_type);
    
    static bool isChar(const std::string & str);
    static bool isInt(const std::string & str);
    static bool isFloat(const std::string & str, t_var & var);
    static bool isDouble(const std::string & str, t_var & var);

    static void print(t_var & var);

    ScalarConverter();
    ~ScalarConverter();
public: 
    static void convert(const char * str);
};

#endif