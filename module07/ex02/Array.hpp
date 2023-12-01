/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:49:25 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/12/01 15:38:52 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <class T>  class Array {
private:
    T*     _array;
    int    _size;
public:
    Array() {
        this->_size = 0;
        this->_array = NULL;
    }
    Array(unsigned int n) {
        this->_size = n;
        this->_array = new T[n];
        for (unsigned int i = 0; i < n; i++) {
            this->_array[i] = T();
        }
    }
    Array(const Array & src) {
        this->_array = NULL;
        *this = src;
    }
    ~Array() {
        delete[] this->_array;
    }

    int size(void) const { return this->_size; }
    
    class OUTOFBOUNDS : public std::exception {
    public:
        virtual const char * what(void) const throw() {
            return "Index Is Out Of Bounds";
        }
    };
    
    Array & operator = (const Array & rhs) {
        if (this->_array)
            delete[] this->_array;

        this->_size     = rhs.size();
        this->_array    = new T[rhs.size()];
        for (int i = 0; i < rhs.size(); i++) {
            (*this)[i] = rhs[i];
        }
        return *this;
    }

    T & operator [] (int idx) const {
        if (idx < 0 || idx >= this->size())
            throw Array::OUTOFBOUNDS();
        return this->_array[idx];
    }
};

#endif