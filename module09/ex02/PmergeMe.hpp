/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:14:43 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/12/15 21:07:33 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <ctime>

std::list<int>  getSequence(char **av);
std::string     convertToString(char **av);
bool            checkSequence(std::string sequence);

// void            firstStepVector(std::vector<int>& vector, std::vector<int>& main, std::vector<int>& pend);
class SortVector {
private:
    std::vector<std::vector<int> >  _pairs;
    std::vector<int>                _vector;
    std::vector<int>                _main;
    std::vector<std::vector<int> >  _reverse;
    std::vector<int>                _pend;
    double                          _time;
    int                             _checkReverse;
    
    SortVector();
    
    static bool    compareVector(std::vector<int> first, std::vector<int> second);
    
    void    convertToPairs(void);
    void    convertToVector(void);
    void    sortPairs(std::vector<std::vector<int> >& vector, size_t pairNum);
    void    sortPair(std::vector<std::vector<int> >& vector);
    void    insertion(std::vector<std::vector<int> >& main, std::vector<std::vector<int> >& pend, int idx);
    void    createChaines(std::vector<std::vector<int> >& reverse, std::vector<std::vector<int> >& main, std::vector<std::vector<int> >& pend);

public:
    SortVector(std::list<int>::iterator begin, std::list<int>::iterator end);
    SortVector(const SortVector & src);
    ~SortVector();

    SortVector &    operator = (const SortVector & rhs);

    double  time(void) const ;
    std::vector<int>    vector(void) const ;
};

class SortDeque {
private:
    std::deque<std::deque<int> >  _pairs;
    std::deque<int>                _deque;
    std::deque<int>                _main;
    std::deque<std::deque<int> >  _reverse;
    std::deque<int>                _pend;
    double                          _time;
    int                             _checkReverse;
    
    SortDeque();
    
    static bool    compareDeque(std::deque<int> first, std::deque<int> second);
    
    void    convertToPairs(void);
    void    convertToDeque(void);
    void    sortPairs(std::deque<std::deque<int> >& deque, size_t pairNum);
    void    sortPair(std::deque<std::deque<int> >& deque);
    void    insertion(std::deque<std::deque<int> >& main, std::deque<std::deque<int> >& pend, int idx);
    void    createChaines(std::deque<std::deque<int> >& reverse, std::deque<std::deque<int> >& main, std::deque<std::deque<int> >& pend);

public:
    SortDeque(std::list<int>::iterator begin, std::list<int>::iterator end);
    SortDeque(const SortDeque & src);
    ~SortDeque();

    SortDeque &    operator = (const SortDeque & rhs);

    double  time(void) const ;
    std::deque<int>    deque(void) const ;
};