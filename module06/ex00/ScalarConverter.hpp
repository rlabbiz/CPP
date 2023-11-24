/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:24:26 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/24 11:21:10 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <cctype>
#include <climits>

typedef enum e_type {
    CHAR,
    INT,
    NOT_INT,
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
    bool    _intPossible;
    n_type  _type;
    n_psude _psude;
    char    _char;
    long     _int;
    float   _float;
    double  _double;

public:
    ScalarConverter();
    ScalarConverter(ScalarConverter const & src);
    ~ScalarConverter();
        
    ScalarConverter & operator = (ScalarConverter const & rhs);

    void    setImpossible(bool impossible);
    void    setIntPossible(bool impossible);
    void    setType(e_type type);
    void    setChar(char c);
    void    setInt(long nbr);
    void    setFloat(float nbr);
    void    setDouble(double nbr);

    bool    getImpossible(void) const ;
    bool    getIntPossible(void) const ;
    n_type  getType(void) const ;
    n_psude getPsude(void) const ;
    char    getChar(void) const ;
    long    getInt(void) const ;
    float   getFloat(void) const ;
    double  getDouble(void) const ;
    
    void    convert(const char * str);
    void    findType(const std::string & str);
    bool    findPsude(const std::string & str);
    void    checkInt(std::string str);
    
    bool    isChar(const std::string & str) const ;
    bool    isInt(const std::string & str) const ;
    bool    isFloat(const std::string & str);
    bool    isDouble(const std::string & str);
};

std::ostream & operator << (std::ostream & out, const ScalarConverter & scal);

#endif