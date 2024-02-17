/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:18:06 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/12/04 07:42:38 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <deque>
#include <list>
#include <stack>

template <class T, class container = std::deque<T> > 
class MutantStack : public std::stack<T, container> {
public:
    MutantStack() {}
    MutantStack(const MutantStack & src) { *this = src; }
    ~MutantStack() {}
    
    MutantStack & operator = (const MutantStack & rhs) {
        std::stack<T, container>::operator=(rhs);
        return *this;
    }

    typedef typename container::iterator                iterator;
    typedef typename container::const_iterator          const_iterator;
    typedef typename container::reverse_iterator        reverse_iterator;
    typedef typename container::const_reverse_iterator  const_reverse_iterator;

    typename container::iterator                begin(void) { return this->c.begin(); }
    typename container::iterator                end(void) { return this->c.end(); }
    typename container::const_iterator          cbegin(void) { return this->c.cbegin(); }
    typename container::const_iterator          cend(void) { return this->c.cend(); }
    typename container::reverse_iterator        rbegin(void) { return this->c.rbegin(); }
    typename container::reverse_iterator        rend(void) { return this->c.rend(); }
    typename container::const_reverse_iterator  crbegin(void) { return this->c.crbegin(); }
    typename container::const_reverse_iterator  crend(void) { return this->c.crend(); }
};

#endif