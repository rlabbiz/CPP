/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:45:17 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/06 12:57:35 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0) { std::cout << "Default constructor called" << '\n'; };

Fixed::Fixed(const int num) {
    std::cout << "Int constructor called" << '\n';
    fixedPoint = num << fractional;
}

Fixed::Fixed(const float num) {
    std::cout << "Float constructor called" << '\n';
    fixedPoint = std::roundf(num * std::pow(2.0f, fractional));
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

bool    Fixed::operator>(const Fixed& next) {
    return fixedPoint > next.fixedPoint;
}

bool    Fixed::operator<(const Fixed& next) {
    return fixedPoint < next.fixedPoint;
}

bool    Fixed::operator>=(const Fixed& next) {
    return fixedPoint >= next.fixedPoint;
}

bool    Fixed::operator<=(const Fixed& next) {
    return fixedPoint <= next.fixedPoint;
}

bool    Fixed::operator==(const Fixed& next) {
    return fixedPoint == next.fixedPoint;
}

bool    Fixed::operator!=(const Fixed& next) {
    return fixedPoint != next.fixedPoint;
}

Fixed   Fixed::operator+(const Fixed& next) {
    Fixed   tmp;

    tmp.fixedPoint = fixedPoint + next.fixedPoint;
    return tmp;
}

Fixed   Fixed::operator-(const Fixed& next) {
    Fixed   tmp;

    tmp.fixedPoint = fixedPoint - next.fixedPoint;
    return tmp;
}

Fixed   Fixed::operator*(const Fixed& next) {
    Fixed tmp;

    tmp.fixedPoint = this->fixedPoint * next.fixedPoint / std::pow(2, fractional);
    return tmp;
}

Fixed   Fixed::operator/(const Fixed& next) {
    Fixed   tmp;

    tmp.fixedPoint = fixedPoint / next.fixedPoint;
    return tmp;
}

Fixed    Fixed::operator++(int) {
    Fixed tmp(*this);
    ++fixedPoint;
    return tmp;
}

Fixed    Fixed::operator++() {
    ++fixedPoint;
    return (*this);
}

Fixed    Fixed::operator--() {
    --fixedPoint;
    return (*this);
}

Fixed   Fixed::operator--(int)  {
    Fixed tmp(*this);
    --fixedPoint;
    return (tmp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    if (a.fixedPoint < b.fixedPoint)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    if (a.fixedPoint > b.fixedPoint)
        return a;
    return b;
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
    return fixedPoint * (1.0f / std::pow(2.0f, fractional));
}

int     Fixed::toInt(void) const {
    return fixedPoint / (1 << fractional);
}

std::ostream & operator << (std::ostream &out, const Fixed &curr) {
    out << curr.toFloat();
    return out;
}
