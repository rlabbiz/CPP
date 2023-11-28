/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:31:25 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/23 20:46:02 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include <exception>

class Btc {
private:
    std::map<std::string, double>  _map;

    Btc();
    
    void        storeData(std::string & line);
    std::string getLowerDate(std::string & date) const ;
public:
    Btc(std::ifstream & file);
    Btc(const Btc& src);
    ~Btc();

    Btc&    operator = (const Btc& rhs);

    class InvalidDate : public std::exception {
        virtual const char * what () const throw();
    };

    class OpenFile : public std::exception {
        virtual const char * what () const throw();
    };
    
    const std::map<std::string, double> &   getMap(void) const ;

    double  at(std::string key) const ;

};

#endif