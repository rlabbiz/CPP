/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:24:23 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/29 21:02:14 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

void    ScalarConverter::checkInt(std::string str, t_var & var) {
    if (str.length() >= 11) {
        var._type = DOUBLE;
        return ;
    }

    long int nbr = std::atol(str.c_str());
    if (nbr < INT_MIN || nbr > INT_MAX) 
        var._type = DOUBLE;
}

void    ScalarConverter::convert(const char * str) {
    t_var var;

    findType(std::string(str), var);
    if (var._type == INT)
        checkInt(std::string(str), var);
    switch (var._type) {
        case CHAR:
            var._char     = str[0];
            var._int      = static_cast<int>(var._char);
            var._float    = static_cast<float>(var._char);
            var._double   = static_cast<double>(var._char);
            break;
        case INT:
            var._int      = std::atol(str);
            var._char     = static_cast<char >(var._int);
            var._float    = static_cast<float>(var._int);
            var._double   = static_cast<double>(var._int);
            break;
        case FLOAT:
            if (var._psude != NONE_PSUDE)
                break ;
            var._float    = std::atof(str);
            var._char     = static_cast<char >(var._float);
            if (var._float >= INT_MIN && var._float <= INT_MAX)
                var._int      = static_cast<int>(var._float);
            else
                var._intPossible = true;
            var._double   = static_cast<double>(var._float);
            break;
        case DOUBLE:
            if (var._psude != NONE_PSUDE)
                break ;
            var._double   = std::atof(str);
            var._char     = static_cast<char >(var._double);
             if (var._double >= INT_MIN && var._double <= INT_MAX)
                var._int      = static_cast<int>(var._double);
            else
                var._intPossible = true;
            var._float    = static_cast<float>(var._double);
            break;
        default:
            var._impossible = true;
    }
    print(var);
}

void    ScalarConverter::findType(const std::string & str, t_var & var) {
    var._impossible   = false;
    var._intPossible  = false;
    var._type         = NONE_TYPE;
    var._psude        = NONE_PSUDE;
    var._char         = '\0';
    var._int          = 0;
    var._float        = 0.0f;
    var._double       = 0.0;
    
    if (isChar(str)) {
        var._type = CHAR;
    } else if (isInt(str)) {
        var._type = INT;
    } else if (isFloat(str, var)) {
        var._type = FLOAT;
    } else if (isDouble(str, var)) {
        var._type = DOUBLE;
    } else {
        var._type = NONE_TYPE;
    }
}

bool    ScalarConverter::findPsude(const std::string & str, t_var & var) {
    if (str == "+inff")
        var._psude = PLUS_INFF;
    else if (str == "-inff")
        var._psude = INFF;
    else if (str == "nanf")
        var._psude = NANF;
    else if (str == "+inf")
        var._psude = PLUS_INF;
    else if (str == "-inf")
        var._psude = INF;
    else if (str == "nan")
        var._psude = NAN;
    else
        var._psude = NONE_PSUDE;
    return true;
}

bool    ScalarConverter::isChar(const std::string & str) {
    if (str.length() != 1 || (str.at(0) >= '0' && str.at(0) <= '9'))
        return false;
    if (str.at(0) < std::numeric_limits<char >::min() || str.at(0) > std::numeric_limits<char >::max())
        return false;
    return true;
}

bool    ScalarConverter::isInt(const std::string & str) {
    size_t i = 0;
    if (str.at(0) == '-' || str.at(0) == '+')
        i++;
    while (i < str.length()) {
        if (str.at(i) < '0' || str.at(i) > '9')
            return false;
        i++;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string & str, t_var & var) {
    if (str == "nanf" || str == "-inff" || str == "+inff")
        return findPsude(str, var);
    if (str.at(str.length() - 1) != 'f')
        return false;
    size_t  i = 0;
    if (str.at(i) == '-' || str.at(i) == '+')
        i++;
    else if (str.at(i) < '0' || str.at(i) > '9')
        return false;
    bool    point = false;
    while (i < str.length() - 1) {
        if (str.at(i) == '.' && point)
            return false;
        else if (str.at(i) == '.')
            point = true;
        else if (str.at(i) < '0' || str.at(i) > '9')
            return false;
        i++;
    }
    return true;
}

bool ScalarConverter::isDouble(const std::string & str, t_var & var) {
    if (str == "nan" || str == "-inf" || str == "+inf")
        return findPsude(str, var);
    size_t  i = 0;
    if (str.at(i) == '-' || str.at(i) == '+')
        i++;
    if (str.at(i) < '0' || str.at(i) > '9')
        return false;
    bool    point = false;
    while (i < str.length()) {
        if (str.at(i) == '.' && point)
            return false;
        else if (str.at(i) == '.')
            point = true;
        else if (str.at(i) < '0' || str.at(i) > '9')
            return false;
        i++;
    }
    return true;
}

std::string  ScalarConverter::getPsudeType(n_psude type, int var_type) {
    switch (type) {
    case NANF:
        if (var_type)
            return "nan";
        else
            return "nanf";
    case PLUS_INFF:
        if (var_type)
            return "+inf";
        else
            return "+inff";
    case INFF:
        if (var_type)
            return "-inf";
        else
            return "-inff";
    case NAN:
        if (var_type)
            return "nan";
        else
            return "nanf";
    case PLUS_INF:
        if (var_type)
            return "+inf";
        else
            return "+inff";
    case INF:
        if (var_type)
            return "-inf";
        else
            return "-inff";
    default:
        break;
    }
    return "impossible";
}

void    ScalarConverter::print(t_var & var) {
    std::cout << "char: ";
    if (var._impossible || var._psude != NONE_PSUDE)
        std::cout << "impossible" << '\n';
    else {
        if (isprint(var._char))
            std::cout << '\'' << var._char << '\'' << '\n';
        else
            std::cout << "Non displayable" << '\n';
    }
    std::cout << "int: ";
    if (var._intPossible || var._impossible || var._psude != NONE_PSUDE)
        std::cout << "impossible" << '\n';
    else
        std::cout << var._int << '\n';
    std::cout << "float: ";
    if (var._impossible || var._psude != NONE_PSUDE)
        std::cout << getPsudeType(var._psude, 0) << '\n';
    else {
        if ((var._float - static_cast<int >(var._float)) == 0.00)
            std::cout << var._float << ".0f" <<'\n';
        else
            std::cout << var._float << "f" << '\n';
    }
    std::cout << "double: ";
    if (var._impossible || var._psude != NONE_PSUDE)
        std::cout << getPsudeType(var._psude, 1) << '\n';
    else {
        if ((var._double - static_cast<int >(var._double)) == 0.00)
            std::cout << var._double << ".0" <<'\n';
        else
            std::cout << var._double << '\n';
    }
}