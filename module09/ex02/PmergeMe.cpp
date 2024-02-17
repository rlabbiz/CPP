/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:14:48 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/12/15 21:23:28 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::string   convertToString(char **av) {
    std::string sequence;
    for (int i = 1; av[i] != NULL; i++) {
        sequence.append(av[i]);
        sequence.append(" ");
    }
    return sequence;
}

bool    checkSequence(std::string sequence) {
    for (size_t i = 0; i < sequence.length(); i++) {
        if (!(sequence.at(i) >= '0' && sequence.at(i) <= '9') && sequence.at(i) != ' ' && sequence.at(i) != '+')
            return false;
    }
    return true;
}

int getNumber(std::string str) {
    long int nbr = std::atol(str.c_str());
    if (nbr < std::numeric_limits<int>::min() || nbr > std::numeric_limits<int>::max()) {
        std::cerr << "Error" << '\n';
        exit(1);
    }
    return static_cast<int>(nbr);
}

std::list<int>  getSequence(char **av) {
    std::string sequenceString = convertToString(av);
    if (!checkSequence(sequenceString)) {
        std::cerr << "Error" << '\n';
        exit(1);
    }
    
    std::stringstream   stream(sequenceString);
    std::list<int>      list;
    std::string         nbr;
    while (stream >> nbr) {
        list.push_back(getNumber(nbr));
    }
    if (list.size() <= 1) {
        std::cerr << "Error" << '\n';
        exit(1);
    }
    return list;
}

void    SortVector::convertToPairs(void) {
    if (this->_vector.size() == 0)
        return ;
    std::vector<int> vector;
    
    vector.push_back(*this->_vector.begin());
    this->_vector.erase(this->_vector.begin());
    
    this->_pairs.push_back(vector);
    
    this->convertToPairs();
}

void    SortVector::sortPair(std::vector<std::vector<int> >& vector) {
    std::vector<int> tmp;
    for (size_t i = 0; i + 1 < vector.size(); i += 2) {
        if (vector[i].back() > vector[i + 1].back()) {
            tmp = vector[i];
            vector[i] =  vector[i + 1];
            vector[i + 1] = tmp;
        }
    }
}

bool SortVector::compareVector(std::vector<int> first, std::vector<int> second) {
    return first.back() < second.back();
}

void    SortVector::insertion(std::vector<std::vector<int> >& main, std::vector<std::vector<int> >& pend, int idx) {
    if (pend.size() == 0 || idx >= 10)
        return ;
    
    size_t jaco[14] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923};
    std::vector<int> element;
    if (jaco[idx] >= pend.size()) {
        for (size_t i = 0; pend.size() != 0; i++) {
            element = *pend.begin();
            pend.erase(pend.begin());
            std::vector<std::vector<int> >::iterator it = std::lower_bound(main.begin(), main.end(), element, compareVector);
            main.insert(it, element);
        }
        return ;
    } else {
        element = *(pend.begin() + jaco[idx]);
        pend.erase(pend.begin() + jaco[idx]);    
    }
    
    std::vector<std::vector<int> >::iterator it = std::lower_bound(main.begin(), main.end(), element, compareVector);
    
    main.insert(it, element);
    
    this->insertion(main, pend, idx + 1);
}

std::vector<std::vector<int> >  newVector(std::vector<std::vector<int> >& list, int pairNum) {
    std::vector<std::vector<int> > vector;
    for (size_t i = 0; i < list.size(); i += pairNum) 
    {
        size_t j = i;
        std::vector<int> element;
        for ( ; j <  i + pairNum && j < list.size(); j++) 
        {
            size_t n;
            for ( n = 0; n < list[j].size(); n++)  {
                element.push_back(list[j][n]);
            }
        }
        vector.push_back(element);
    }
    return vector;
}

std::vector<std::vector<int> >  newReverseVector(std::vector<std::vector<int> >& vector) {
    std::vector<std::vector<int> > reverse;

    for (size_t i = 0; i < vector.size(); i++) {
        size_t j = 0;
        std::vector<int> ele1;
        std::vector<int> ele2;
        if (vector[i].size() == 1) {
            for ( ; j < vector[i].size(); j++) 
                ele1.push_back(vector[i][j]);
            reverse.push_back(ele1);
            continue ;
        }
        for ( ; j < vector[i].size() / 2; j++) 
            ele1.push_back(vector[i][j]);
        reverse.push_back(ele1);
        for ( ; j < vector[i].size(); j++) 
            ele2.push_back(vector[i][j]);
        reverse.push_back(ele2);
    }
    return reverse;
}

void    SortVector::createChaines(std::vector<std::vector<int> >& reverse, std::vector<std::vector<int> >& main, std::vector<std::vector<int> >& pend) {
    if (reverse.size() >= 2) {
        main.push_back(reverse[0]);
        main.push_back(reverse[1]);
    } else if (reverse.size() == 1)
        main.push_back(reverse[0]);
    
    for (size_t i = 2; i < reverse.size(); i++) {
        pend.push_back(reverse[i]);
        if (i + 1 < reverse.size()) {
            main.push_back(reverse[i + 1]);
            i++;
        }
    }
}

void    SortVector::convertToVector(void) {
    this->_vector.clear();
    for (size_t i = 0; i < this->_reverse.size(); i++)
        this->_vector.push_back(this->_reverse[i].back());
}

void    SortVector::sortPairs(std::vector<std::vector<int> >& list, size_t pairNum) 
{
    if (list.size() == 1)
        return ;
    this->_checkReverse = 0;
    if (pairNum > 2)
        pairNum /= 2;
    
    std::vector<std::vector<int> >  tmp;
    int                             checkTmp = 0;

    if (list.size() % 2 != 0) {
        checkTmp = 1;
        tmp.push_back(list.back());
        list.erase(list.end() - 1);
    }

    std::vector<std::vector<int> > vector = newVector(list, pairNum);
    
    this->sortPair(vector);
    this->_pairs.clear();
    this->_pairs = vector;
    this->sortPairs(vector, pairNum * 2);

    if (!this->_checkReverse)
        this->_checkReverse = 1;
    else {
        vector.clear();
        vector = this->_reverse;
    }

    std::vector<std::vector<int> > reverse = newReverseVector(vector);
    std::vector<std::vector<int> > main;
    std::vector<std::vector<int> > pend;

    createChaines(reverse, main, pend);

    if (checkTmp){
        for (size_t i = 0; i < tmp.size(); i++)
            pend.push_back(tmp[i]);
    }

    this->insertion(main, pend, 0);
   
    this->_reverse.clear();
    this->_reverse = main;
}

SortVector::SortVector() {}

SortVector::SortVector(std::list<int>::iterator begin, std::list<int>::iterator end) {
    std::clock_t time = clock();
    for (; begin != end; begin++)
        this->_vector.push_back(*begin);
    
    this->convertToPairs();
    
    this->sortPairs(this->_pairs, 1);

    time = clock() - time;
    this->_vector = this->_main;
    this->_time = (double)(time / (double)CLOCKS_PER_SEC);

    this->convertToVector();
}

SortVector::SortVector(const SortVector & src) { *this = src; }

SortVector::~SortVector() {}

SortVector &    SortVector::operator = (const SortVector & rhs) {
    this->_vector = rhs.vector();
    return *this;
}

double  SortVector::time(void) const { return this->_time; }

std::vector<int>    SortVector::vector(void) const { return this->_vector; }

//////////////////////////////////////////////////////

void    SortDeque::convertToPairs(void) {
    if (this->_deque.size() == 0)
        return ;
    std::deque<int> deque;
    
    deque.push_back(*this->_deque.begin());
    this->_deque.erase(this->_deque.begin());
    
    this->_pairs.push_back(deque);
    
    this->convertToPairs();
}

void    SortDeque::sortPair(std::deque<std::deque<int> >& deque) {
    std::deque<int> tmp;
    for (size_t i = 0; i + 1 < deque.size(); i += 2) {
        if (deque[i].back() > deque[i + 1].back()) {
            tmp = deque[i];
            deque[i] =  deque[i + 1];
            deque[i + 1] = tmp;
        }
    }
}

bool SortDeque::compareDeque(std::deque<int> first, std::deque<int> second) {
    return first.back() < second.back();
}

void    SortDeque::insertion(std::deque<std::deque<int> >& main, std::deque<std::deque<int> >& pend, int idx) {
    if (pend.size() == 0 || idx >= 10)
        return ;
    
    size_t jaco[14] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923};
    std::deque<int> element;
    if (jaco[idx] >= pend.size()) {
        for (size_t i = 0; pend.size() != 0; i++) {
            element = *pend.begin();
            pend.erase(pend.begin());
            std::deque<std::deque<int> >::iterator it = std::lower_bound(main.begin(), main.end(), element, compareDeque);
            main.insert(it, element);
        }
        return ;
    } else {
        element = *(pend.begin() + jaco[idx]);
        pend.erase(pend.begin() + jaco[idx]);    
    }
    
    std::deque<std::deque<int> >::iterator it = std::lower_bound(main.begin(), main.end(), element, compareDeque);
    
    main.insert(it, element);
    
    this->insertion(main, pend, idx + 1);
}

std::deque<std::deque<int> >  newdeque(std::deque<std::deque<int> >& list, int pairNum) {
    std::deque<std::deque<int> > deque;
    for (size_t i = 0; i < list.size(); i += pairNum) 
    {
        size_t j = i;
        std::deque<int> element;
        for ( ; j <  i + pairNum && j < list.size(); j++) 
        {
            size_t n;
            for ( n = 0; n < list[j].size(); n++)  {
                element.push_back(list[j][n]);
            }
        }
        deque.push_back(element);
    }
    return deque;
}

std::deque<std::deque<int> >  newReversedeque(std::deque<std::deque<int> >& deque) {
    std::deque<std::deque<int> > reverse;

    for (size_t i = 0; i < deque.size(); i++) {
        size_t j = 0;
        std::deque<int> ele1;
        std::deque<int> ele2;
        if (deque[i].size() == 1) {
            for ( ; j < deque[i].size(); j++) 
                ele1.push_back(deque[i][j]);
            reverse.push_back(ele1);
            continue ;
        }
        for ( ; j < deque[i].size() / 2; j++) 
            ele1.push_back(deque[i][j]);
        reverse.push_back(ele1);
        for ( ; j < deque[i].size(); j++) 
            ele2.push_back(deque[i][j]);
        reverse.push_back(ele2);
    }
    return reverse;
}

void    SortDeque::createChaines(std::deque<std::deque<int> >& reverse, std::deque<std::deque<int> >& main, std::deque<std::deque<int> >& pend) {
    if (reverse.size() >= 2) {
        main.push_back(reverse[0]);
        main.push_back(reverse[1]);
    } else if (reverse.size() == 1)
        main.push_back(reverse[0]);
    
    for (size_t i = 2; i < reverse.size(); i++) {
        pend.push_back(reverse[i]);
        if (i + 1 < reverse.size()) {
            main.push_back(reverse[i + 1]);
            i++;
        }
    }
}

void    SortDeque::convertToDeque(void) {
    this->_deque.clear();
    for (size_t i = 0; i < this->_reverse.size(); i++)
        this->_deque.push_back(this->_reverse[i].back());
}

void    SortDeque::sortPairs(std::deque<std::deque<int> >& list, size_t pairNum) 
{
    if (list.size() == 1)
        return ;
    this->_checkReverse = 0;
    if (pairNum > 2)
        pairNum /= 2;
    
    std::deque<std::deque<int> >  tmp;
    int                             checkTmp = 0;

    if (list.size() % 2 != 0) {
        checkTmp = 1;
        tmp.push_back(list.back());
        list.erase(list.end() - 1);
    }

    std::deque<std::deque<int> > deque = newdeque(list, pairNum);
    
    this->sortPair(deque);
    this->_pairs.clear();
    this->_pairs = deque;
    this->sortPairs(deque, pairNum * 2);

    if (!this->_checkReverse)
        this->_checkReverse = 1;
    else {
        deque.clear();
        deque = this->_reverse;
    }

    std::deque<std::deque<int> > reverse = newReversedeque(deque);
    std::deque<std::deque<int> > main;
    std::deque<std::deque<int> > pend;

    createChaines(reverse, main, pend);

    if (checkTmp){
        for (size_t i = 0; i < tmp.size(); i++)
            pend.push_back(tmp[i]);
    }

    this->insertion(main, pend, 0);
   
    this->_reverse.clear();
    this->_reverse = main;
}

SortDeque::SortDeque() {}

SortDeque::SortDeque(std::list<int>::iterator begin, std::list<int>::iterator end) {
    std::clock_t time = clock();
    for (; begin != end; begin++)
        this->_deque.push_back(*begin);
    
    this->convertToPairs();
    
    this->sortPairs(this->_pairs, 1);

    time = clock() - time;
    this->_deque = this->_main;
    this->_time = (double)(time / (double)CLOCKS_PER_SEC);

    this->convertToDeque();
}

SortDeque::SortDeque(const SortDeque & src) { *this = src; }

SortDeque::~SortDeque() {}

SortDeque &    SortDeque::operator = (const SortDeque & rhs) {
    this->_deque = rhs.deque();
    return *this;
}

double  SortDeque::time(void) const { return this->_time; }

std::deque<int>    SortDeque::deque(void) const { return this->_deque; }
