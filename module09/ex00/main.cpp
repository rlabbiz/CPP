/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:31:27 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/12/14 12:53:11 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Btc*    insertDb(const char * fileName) {
    std::ifstream file(fileName);
    try {
        Btc* btc = new Btc(file);
        file.close();
        return btc;
    } catch (std::exception & e) {
        std::cerr << e.what() << '\n';
    }
    return NULL;
}

int checkPrix(std::string str) {
    double prix = std::stod(str);
    if (prix > 1000) {
        std::cout << "Error: too large a number." << '\n';
        return 1;
    } else if (prix < 0) {
        std::cout << "Error: not a positive number." << '\n';
        return 1;
    }
    return 0;
}

int checkDateRange(std::string str) {
    size_t      idx     = str.find("-");
    size_t      idx2    = str.find("-", idx + 1);
    std::string s_year  = str.substr(0, idx);
    std::string s_month = str.substr(idx + 1, idx2 - (idx + 1));
    std::string s_day   = str.substr(idx2 + 1);
    
    int year    = std::atoi(s_year.c_str());
    int month   = std::atoi(s_month.c_str());
    int day     = std::atoi(s_day.c_str());

    if (year < 2006 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31 ) {
        std::cout << "Error: bad input => " << str << '\n';
        return 1;
    }
    return 0;
}

int checkDate(std::string str) {
    str.erase(std::remove(str.begin(), str.end(), ' '));
    for (size_t i = 0; i < str.length(); i++) {
        if (str.at(i) != '-' && !(str.at(i) >= '0' && str.at(i) <= '9')){
            std::cout << "Error: bad input => " << str << '\n';
            return 1;
        }
    }

    size_t idx = str.find("-", 0);
    idx = str.find("-", idx + 1);
    if (idx == std::string::npos) {
        std::cout << "Error: bad input => " << str << '\n';
        return 1;
    }
    idx = str.find("-", idx + 1);
    if (idx != std::string::npos) {
        std::cout << "Error: bad input => " << str << '\n';
        return 1;
    }
    return checkDateRange(str);
}

int checkValidDate(std::string line) {
    std::stringstream s(line);
    
    std::string date;
    std::string prix;
    std::string rest;

    s >> date;
    s >> prix;
    prix.clear();
    s >> prix;
    s >> rest;

    if (date.empty() || prix.empty() || !rest.empty()) {
        std::cerr << "Error: bad input => " << line << '\n';
        return 1;
    }
    if (checkPrix(prix) || checkDate(date))
        return 1;
    return 0;
}

void    printLine(Btc* btc, std::string line) {
    size_t idx = line.find("|");
    if (idx == std::string::npos){
        std::cout << "Error: bad input => " << line << '\n';
        return ;
    }
    if (checkValidDate(line))
        return ;
    
    std::string s_date  = line.substr(0, idx);
    std::string s_prix  = line.substr(idx + 1);
    double      prix    = std::stod(s_prix);
    
    s_date.erase(std::remove(s_date.begin(), s_date.end(), ' '));
    double  key = btc->at(s_date);
    
    std::cout << s_date << " => " << prix << " = " << key * prix <<'\n';
}

int checkFirstLine(std::string str) {
    std::stringstream   s(str);
    std::string         subString;
    
    s >> subString;
    if (subString != "date")
        return 1;
    s >> subString;
    if (subString != "|")
        return 1;
    s >> subString;
    if (subString != "value")
        return 1;
    subString.clear();
    s >> subString;
    if (!subString.empty())
        return 1;
    return 0;
}

int main(int ac, char **av) {

    if (ac < 2) {
        std::cerr << "Error: Bad arguments." << '\n';
        std::cerr << "\tUsage: ./btc input.txt" << '\n';
        return 1;
    }

    Btc* btc = insertDb("data.csv");
    if (!btc)
        return 1;
    
    std::ifstream   file(av[1]);
    if (!file.is_open()) {
        std::cout << "Error: can't open file " << av[1] << " for reading." << '\n';
        return 1;
    }

    std::string line;

    while (file) {
        std::getline(file, line);
        if (!line.empty()) {
            break ;
        }
    }
    if (line.empty()) {
        std::cerr << "Error: file is empty." << '\n';
        return 1;
    }
    if (checkFirstLine(line)) {
        std::cerr << "Error: invalid line: " << line << '\n';
        return 1;
    }
    line.clear();
    while (file) {
        std::getline(file, line);
        if (line.empty())
            continue ;
        printLine(btc, line);
        line.clear();
    }
    
    file.close();
    delete btc;
}
