/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:15:13 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/12/02 23:14:53 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span {
private:
    std::vector<int>    _array;
    int                 _capacity;
    int                 _len;
    
    Span();
public:
    Span(unsigned int N);
    Span(const Span& src);
    ~Span();
    
    Span&  operator = (const Span& rhs);

    std::vector<int>    getArray(void) const ;
    int                 getLen(void) const ;
    int                 getCapacity(void) const ;

    void    addNumber(int n);
    void    addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);
    int     shortestSpan(void) const ;
    int     longestSpan(void) const ;
};

#endif