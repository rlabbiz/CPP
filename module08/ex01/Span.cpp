/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:15:15 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/12/01 16:50:26 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : _capacity(N), _len(0) {}

Span::Span(const Span& src) { *this = src; }

Span::~Span() { }

Span&   Span::operator = (const Span& rhs) {
    if (this == &rhs)
        return *this;
    this->_array    = rhs.getArray();
    this->_capacity = rhs.getCapacity();
    this->_len      = rhs.getLen();
    return *this;
}

std::vector<int>    Span::getArray(void) const { return this->_array; }
int                 Span::getLen(void) const { return this->_len; }
int                 Span::getCapacity(void) const { return this->_capacity; }

void    Span::addNumber(int n) {
    if (this->_len == this->_capacity)
        throw   "No space left to add new number.";
    this->_array.push_back(n);
    this->_len++;
}

void    Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last) {
    for (; first != last; first++) {
        this->addNumber(*first);
    }     
}

int Span::shortestSpan(void) const {
    if (this->_len <= 1)
        throw "Not enough numbers.";

    std::vector<int>::const_iterator lastElement   = this->_array.end();
    lastElement--;
    std::vector<int>::const_iterator firstElement  = this->_array.end();
    firstElement--;
    firstElement--;
    return *lastElement - *firstElement;
}

int Span::longestSpan(void) const {
    if (this->_len <= 1)
        throw "Not enough numbers.";

    std::vector<int>::const_iterator    minNumber = std::min_element(this->_array.begin(), this->_array.end());
    std::vector<int>::const_iterator    maxNumber = std::max_element(this->_array.begin(), this->_array.end());
    return *maxNumber - *minNumber;
}
