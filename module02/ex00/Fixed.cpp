/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:45:17 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/02 13:23:15 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0){ std::cout << "Default constructor called" << '\n'; };

Fixed::Fixed(Fixed &tmp) {
    std::cout << "Copy constructor called" << '\n';
    (*this) = tmp;
}

Fixed::~Fixed() { std::cout << "Destructor called" << '\n'; }

Fixed&  Fixed::operator=(const Fixed& next){
    std::cout << "Copy assignment operator called" << '\n';
    fixedPoint = next.getRawBits();
    return (*this);
}

int     Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << '\n';
    return fixedPoint; 
}
void    Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << '\n';
    fixedPoint = raw;
}
