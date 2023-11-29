/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:18:06 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/25 17:07:44 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <deque>
#include <stack>

template <class T, class container = std::deque<T> > 
class MutantStack : public std::stack<T, container> {
public:
    MutantStack() : std::stack<T, container> () {};
    typedef typename container::iterator    iterator;
    typename container::iterator begin(void) { return this->c.begin(); }
    typename container::iterator end(void) { return this->c.end(); }
    
};

#endif