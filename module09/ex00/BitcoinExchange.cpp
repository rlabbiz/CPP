/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:31:29 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/23 13:17:02 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Btc::Btc() {}

Btc::Btc(std::ifstream & file) {
    if (!file.is_open())
        throw  Btc::OpenFile();

    std::string line;
    
    std::getline(file, line);
    if (line.empty())
        return ;
    line.clear();
    while (file) {
        std::getline(file, line);
        if (line.empty())
            break ;
        this->storeData(line);
        line.clear();
    }
}

Btc::Btc(const Btc& src) { *this = src; }

Btc::~Btc() {}

Btc&    Btc::operator = (const Btc& rhs) { (void)rhs; return *this; }

const char * Btc::InvalidDate::what() const throw() {
    return ("Invalid Date");
}

const char * Btc::OpenFile::what() const throw() {
    return ("Can't Open File");
}

void    Btc::storeData(std::string & line) {
    std::string date = line.substr(0, 10);
    double       prix = std::atof(line.substr(11).c_str());

    this->_map[date] = prix;
}

std::string Btc::getLowerDate(std::string & data) const {
    std::string s_year  = data.substr(0, 4);
    std::string s_month = data.substr(5, 2);
    std::string s_day   = data.substr(8, 2);

    int year    = std::atoi(s_year.c_str());
    int month   = std::atoi(s_month.c_str());
    int day     = std::atoi(s_day.c_str());
    
    if (day > 1)
        day--;
    else if (month > 1)
        month--;
    else if (year > 2009)
        year--;
    else
        throw Btc::InvalidDate();
    
    std::string result;
    s_year      = std::to_string(year);
    s_month     = std::to_string(month);
    s_day       = std::to_string(day);

    result.append(s_year);
    result.append("-");
    if (month <= 9)
        result.append("0");
    result.append(s_month);
    result.append("-");
    if (day <= 9)
        result.append("0");
    result.append(s_day);

    return (result);
}

const std::map<std::string, double> &   Btc::getMap(void) const { return this->_map; }

double Btc::at(std::string key) const {
    std::map<std::string, double>::const_iterator it = this->_map.begin();

    for (; it != this->_map.end(); it++) {
        if (key == it->first)
            return it->second;
    }
    return (this->at(this->getLowerDate(key)));
}
