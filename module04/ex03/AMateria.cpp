/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:29:15 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/14 22:27:09 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
    std::cout << "AMateria: Default constructor called." << '\n';
}

AMateria::AMateria(std::string const & type) : type(type) {
    std::cout << "AMateria: constructor called." << '\n';
}

AMateria::AMateria(AMateria const & tmp) {
    std::cout << "AMateria: Copy constructor called." << '\n';
    *this = tmp;
}

AMateria::~AMateria() {
    std::cout << "AMateria: Destructor alled." << '\n';
}

AMateria &  AMateria::operator = (const AMateria & next) {
    std::cout << "AMateria: Assignment operator called." << '\n';
    if (this == &next)
        return *this;
    this->type = next.type;
    return *this;
}

std::string const & AMateria::getType() const { return this->type; }

