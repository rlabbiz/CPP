/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:45:17 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/03 15:49:53 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0) { std::cout << "Default constructor called" << '\n'; };

Fixed::Fixed(const int num) {
    std::cout << "Int constructor called" << '\n';
    fixedPoint = num * std::pow(2.0f, fractional);
}

Fixed::Fixed(const float num) {
    std::cout << "Float constructor called" << '\n';
    fixedPoint = std::round(num * std::pow(2.0f, fractional));
}

Fixed::Fixed(const Fixed &tmp) {
    std::cout << "Copy constructor called" << '\n';
    (*this) = tmp;
}

Fixed::~Fixed() { std::cout << "Destructor called" << '\n'; }

Fixed&  Fixed::operator=(const Fixed& next) {
    std::cout << "Copy assignment operator called" << '\n';
    fixedPoint = next.fixedPoint;
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

float   Fixed::toFloat(void) const {
    return fixedPoint / std::pow(2.0f, fractional);
}

int     Fixed::toInt(void) const {
    return fixedPoint / (std::pow(2.0f, fractional));
}

std::ostream & operator << (std::ostream &out, const Fixed &curr) {
    out << curr.toFloat();
    return out;
}
