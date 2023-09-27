/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:35:17 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/27 16:06:46 by rlabbiz          ###   ########.fr       */
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

void    Harl::complain(std::string level) {
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

    while (i < 4){
        if (arr[i] == level){
            (this->*ptr[i])();
            break ;
        }
        i++;
    }
}