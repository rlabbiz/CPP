/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:35:17 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/27 16:08:50 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void    Harl::debug(void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << '\n';
}

void    Harl::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << '\n';
}

void    Harl::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << '\n';
}

void    Harl::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << '\n';
}

void    Harl::harlFilter(std::string level) {
    std::string arr[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    void        (Harl::*ptr[])() = {
        &Harl::debug, 
        &Harl::info, 
        &Harl::warning, 
        &Harl::error
    };
    int         i = 0;
    int         index = -1;

    while (i < 4){
        if (arr[i] == level){
            index = i;
            break ;
        }
        i++;
    }

    switch (index) {
        case 0: 
            (this->*ptr[0])();
            (this->*ptr[1])();
            (this->*ptr[2])();
            (this->*ptr[3])();
            break;
        case 1:
            (this->*ptr[1])();
            (this->*ptr[2])();
            (this->*ptr[3])();
            break;
        case 2:
            (this->*ptr[2])();
            (this->*ptr[3])();
            break;
        case 3:
            (this->*ptr[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << '\n';
    }
}

/*
void    Harl::harlFilter(std::string level) {
    void        (Harl::*ptr[])() = {
        &Harl::debug, 
        &Harl::info, 
        &Harl::warning, 
        &Harl::error
    };
    int         index = -1;

    switch (level.c_str()) {
        case "DEBUG": 
            index = 0;
            break;
        case "INFO":
            index = 1;
            break;
        case "WARNING":
            index = 2;
            break;
        case "ERROR":
            index = 3;
            break;
        default:
            index = -1;
    }
    if (index == -1){
        std::cout << "[ Probably complaining about insignificant problems ]" << '\n';
        return ;
    }
    while (index < 4){
        (this->*ptr[index])();
        index++;
    }
}
*/