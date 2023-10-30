/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:19:01 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/30 19:52:37 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() { }

Intern::Intern(const Intern & src) { (void)src; }

Intern::~Intern() { }

Intern & Intern::operator = (const Intern & rhs) { (void)rhs; return *this; }

Form    *Intern::makeForm(std::string form, std::string target) {
    std::string forms[3] = {"robotomy request", "shrubbery request", "presidential request"};
    int         check = 1;
    int         i = 0;

    while (i < 3) {
        if (form == forms[i]) {
            check = 0;
            break ;
        }
        i++;
    }
    if (check)
        return NULL;
    switch (i) {
        case 0:
            return new RobotomyRequestForm(target);
        case 1:
            return new ShrubberyCreationForm(target);
        case 2:
            return new PresidentialPardonForm(target);
    }
    return NULL;
}