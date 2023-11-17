/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:24:26 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/14 17:13:26 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <cctype>

typedef enum e_type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    NONE_TYPE,
}   n_type;

typedef enum e_psude {
    PLUS_INFF,
    INFF,
    NANF,
    PLUS_INF,
    INF,
    NAN,
    NONE_PSUDE,
}   n_psude;


class ScalarConverter {
private:
    bool    _impossible;
    n_type  _type;
    n_psude _psude;
    char    _char;
    int     _int;
    float   _float;
    double  _double;

public:
    ScalarConverter();
    ScalarConverter(ScalarConverter const & src);
    ~ScalarConverter();
        
    ScalarConverter & operator = (ScalarConverter const & rhs);

    void    setImpossible(bool impossible);
    void    setType(e_type type);
    void    setChar(char c);
    void    setInt(int nbr);
    void    setFloat(float nbr);
    void    setDouble(double nbr);

    bool    getImpossible(void) const ;
    n_type  getType(void) const ;
    n_psude getPsude(void) const ;
    char    getChar(void) const ;
    int     getInt(void) const ;
    float   getFloat(void) const ;
    double  getDouble(void) const ;
    
    void    convert(const char * str);
    void    findType(const std::string & str);
    bool    findPsude(const std::string & str);
    
    bool    isChar(const std::string & str) const ;
    bool    isInt(const std::string & str) const ;
    bool    isFloat(const std::string & str);
    bool    isDouble(const std::string & str);

};

// int     ft_toInt(const char * str);
// float   ft_toFloat(const char * str);
// double  ft_toDouble(const char * str);

std::ostream & operator << (std::ostream & out, const ScalarConverter & scal);

#endif