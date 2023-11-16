/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:49:25 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/16 15:15:59 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <class T>  class Array {
private:
    T*              _array;
    int    _size;
public:
    Array() {
        this->_array = new T[3];
    }
    Array(unsigned int n) {
        this->_array = new T[n];
    }
    Array(const Array & src) {
        this->_array = new T[3];
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
        delete[] this->_array;

        this->_array = new T(rhs.size());
        
        for (int i = 0; i < rhs.size(); i++) {
            (*this)[i] = rhs[i];
        }
        return *this;
    }
    
    T   operator [] (int idx) const {
        if (idx < 0 || idx >= this->size())
            throw Array::OUTOFBOUNDS();
        return  this->_array[idx];
    }

    T & operator [] (int idx) {
        if (idx < 0 || idx >= this->size())
            throw Array::OUTOFBOUNDS();
        return this->_array[idx];
    }
};

#endif