/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:24:23 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/24 17:08:21 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    this->_impossible   = false;
    this->_intPossible   = false;
    this->_type         = NONE_TYPE;
    this->_psude        = NONE_PSUDE;
    this->_char         = '\0';
    this->_int          = 0;
    this->_float        = 0.0f;
    this->_double       = 0.0;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src) { *this = src; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter & ScalarConverter::operator = (ScalarConverter const & rhs) {
    this->_impossible   = rhs.getImpossible();
    this->_intPossible  = rhs.getIntPossible();
    this->_type         = rhs.getType();
    this->_psude        = rhs.getPsude();
    this->_char         = rhs.getChar();
    this->_int          = rhs.getInt();
    this->_float        = rhs.getFloat();
    this->_double       = rhs.getDouble();
    return *this;
}

void    ScalarConverter::setImpossible(bool impossible) { this->_impossible = impossible; }
void    ScalarConverter::setIntPossible(bool intPossible) { this->_intPossible = intPossible; }
void    ScalarConverter::setType(e_type type) { this->_type = type; }
void    ScalarConverter::setChar(char c) { this->_char = c; }
void    ScalarConverter::setInt(long nbr) { this->_int = nbr; }
void    ScalarConverter::setFloat(float nbr) { this->_float = nbr; }
void    ScalarConverter::setDouble(double nbr) { this->_double = nbr; }

bool    ScalarConverter::getImpossible(void) const { return this->_impossible; }
bool    ScalarConverter::getIntPossible(void) const { return this->_intPossible; }
n_type  ScalarConverter::getType(void) const { return this->_type; }
n_psude ScalarConverter::getPsude(void) const { return this->_psude; }
char    ScalarConverter::getChar(void) const { return this->_char; }
long    ScalarConverter::getInt(void) const { return this->_int; }
float   ScalarConverter::getFloat(void) const { return this->_float; }
double  ScalarConverter::getDouble(void) const { return this->_double; }

void    ScalarConverter::checkInt(std::string str) {
    if (str.length() >= 11) {
        this->_type = DOUBLE;
        return ;
    }

    long nbr = std::stol(str);
    if (nbr < INT_MIN || nbr > INT_MAX) 
        this->_type = DOUBLE;
}

void    ScalarConverter::convert(const char * str) {
    this->findType(std::string(str));
    if (this->_type == INT)
        this->checkInt(std::string(str));
    switch (this->_type) {
        case CHAR:
            this->_char     = str[0];
            this->_int      = static_cast<int>(this->_char);
            this->_float    = static_cast<float>(this->_char);
            this->_double   = static_cast<double>(this->_char);
            break;
        case INT:
            this->_int      = std::stol(str);
            this->_char     = static_cast<char >(this->_int);
            this->_float    = static_cast<float>(this->_int);
            this->_double   = static_cast<double>(this->_int);
            break;
        case FLOAT:
            if (this->_psude != NONE_PSUDE)
                return ;
            this->_float    = std::atof(str);
            this->_char     = static_cast<char >(this->_float);
            if (this->_float >= INT_MIN && this->_float <= INT_MAX)
                this->_int      = static_cast<int>(this->_float);
            else
                this->_intPossible = true;
            this->_double   = static_cast<double>(this->_float);
            break;
        case DOUBLE:
            if (this->_psude != NONE_PSUDE)
                return ;
            this->_double   = std::atof(str);
            this->_char     = static_cast<char >(this->_double);
             if (this->_double >= INT_MIN && this->_double <= INT_MAX)
                this->_int      = static_cast<int>(this->_double);
            else
                this->_intPossible = true;
            this->_float    = static_cast<float>(this->_double);
            break;
        default:
            this->_impossible = true;
    }
}

void    ScalarConverter::findType(const std::string & str) {
    if (this->isChar(str)) {
        this->_type = CHAR;
    } else if (this->isInt(str)) {
        this->_type = INT;
    } else if (this->isFloat(str)) {
        this->_type = FLOAT;
    } else if (this->isDouble(str)) {
        this->_type = DOUBLE;
    } else {
        this->_type = NONE_TYPE;
    }
}

bool    ScalarConverter::findPsude(const std::string & str) {
    if (str == "+inff")
        this->_psude = PLUS_INFF;
    else if (str == "-inff")
        this->_psude = INFF;
    else if (str == "nanf")
        this->_psude = NANF;
    else if (str == "+inf")
        this->_psude = PLUS_INF;
    else if (str == "-inf")
        this->_psude = INF;
    else if (str == "nan")
        this->_psude = NAN;
    else
        this->_psude = NONE_PSUDE;
    return true;
}

bool    ScalarConverter::isChar(const std::string & str) const {
    if (str.length() != 1 || (str.at(0) >= '0' && str.at(0) <= '9'))
        return false;
    if (str.at(0) < std::numeric_limits<char >::min() || str.at(0) > std::numeric_limits<char >::max())
        return false;
    return true;
}

bool    ScalarConverter::isInt(const std::string & str) const {
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

bool ScalarConverter::isFloat(const std::string & str) {
    if (str == "nanf" || str == "-inff" || str == "+inff")
        return findPsude(str);
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

bool ScalarConverter::isDouble(const std::string & str) {
    if (str == "nan" || str == "-inf" || str == "+inf")
        return findPsude(str);
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

std::string  getPsudeType(n_psude type, int var_type) {
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
            return "inf";
        else
            return "inff";
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
            return "inf";
        else
            return "inff";
    default:
        break;
    }
    return "impossible";
}

std::ostream & operator << (std::ostream & out, const ScalarConverter & scal) {
    out << "char: ";
    if (scal.getImpossible() || scal.getPsude() != NONE_PSUDE)
        out << "impossible" << '\n';
    else {
        if (isprint(scal.getChar()))
            out << '\'' << scal.getChar() << '\'' << '\n';
        else
            out << "Non displayable" << '\n';
    }
    out << "int: ";
    if (scal.getIntPossible() || scal.getImpossible() || scal.getPsude() != NONE_PSUDE)
        out << "impossible" << '\n';
    else
        out << scal.getInt() << '\n';
    out << "float: ";
    if (scal.getImpossible() || scal.getPsude() != NONE_PSUDE)
        out << getPsudeType(scal.getPsude(), 0) << '\n';
    else {
        if ((scal.getFloat() - static_cast<int >(scal.getFloat())) == 0.00)
            out << scal.getFloat() << ".0f" <<'\n';
        else
            out << scal.getFloat() << "f" << '\n';
    }
    out << "double: ";
    if (scal.getImpossible() || scal.getPsude() != NONE_PSUDE)
        out << getPsudeType(scal.getPsude(), 1) << '\n';
    else {
        if ((scal.getDouble() - static_cast<int >(scal.getDouble())) == 0.00)
            out << scal.getDouble() << ".0" <<'\n';
        else
            out << scal.getDouble() << '\n';
    }
    return out;
}