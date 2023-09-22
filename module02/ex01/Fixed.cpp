/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:45:17 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/22 17:06:17 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0){ std::cout << "Default constructor called" << '\n'; };

Fixed::Fixed(const int num) {
    std::cout << "Int constructor called" << '\n';
    isFloat = false;
    fixedPoint = num << fractional;
}

Fixed::Fixed(const float num) {
    std::cout << "Float constructor called" << '\n';
    isFloat = true;
    floatFixedPoint = num;
}

Fixed::Fixed(const Fixed &tmp) {
    std::cout << "Copy constructor called" << '\n';
    fixedPoint = tmp.fixedPoint;
}

Fixed::~Fixed() { std::cout << "Destructor called" << '\n'; }

int     Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << '\n';
    return fixedPoint;
}

void    Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << '\n';
    fixedPoint = raw;
}
