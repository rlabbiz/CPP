/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:14:43 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/12/06 12:42:23 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <algorithm>

std::list<int>  getSequence(char **av);
std::string     convertToString(char **av);
bool            checkSequence(std::string sequence);

void            firstStepVector(std::vector<int>& vector, std::vector<int>& main, std::vector<int>& pend);
class SortVector {
private:
    std::vector<std::vector<int> >  _pairs;
    std::vector<int>                _vector;
    std::vector<int>                _main;
    std::vector<int>                _pend;
    int                             _lastElement;
    
    SortVector();
    
    void    convertToPairs(void);
    void    sortPairs(void);
    int     getLastElement(void);
    void    createChains(void);
    void    insertion(void);

public:
    SortVector(std::list<int>::iterator begin, std::list<int>::iterator end);
    SortVector(const SortVector & src);
    ~SortVector();

    SortVector &    operator = (const SortVector & rhs);
};