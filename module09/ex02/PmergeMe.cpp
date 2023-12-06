/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:14:48 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/12/06 14:53:18 by rlabbiz          ###   ########.fr       */
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
    return list;
}

void    firstStepVector(std::vector<int>& vector, std::vector<int>& main, std::vector<int>& pend) {
    if (vector.size() < 2)
        return ;
        std::vector<int>::iterator element1 = std::max_element(vector.begin(), vector.begin() + 2);
        std::vector<int>::iterator element2 = std::min_element(vector.begin(), vector.begin() + 2);

        main.push_back(*element1);
        pend.push_back(*element2);

        vector.erase(vector.begin());
        vector.erase(vector.begin());

        if (vector.size() > 1)
            firstStepVector(vector, main, pend);
}

int SortVector::getLastElement(void) {
    int lastElement = -1;
    if (this->_vector.size() % 2) {
        lastElement = this->_vector.back();
        this->_vector.pop_back();
    }
    return lastElement;
}

void    SortVector::convertToPairs(void) {
    if (this->_vector.size() < 2)
        return ;
    std::vector<int> vector;
    
    vector.push_back(*this->_vector.begin());
    this->_vector.erase(this->_vector.begin());
    
    vector.push_back(*this->_vector.begin());
    this->_vector.erase(this->_vector.begin());
    
    this->_pairs.push_back(vector);
    
    this->convertToPairs();
}

void    SortVector::sortPairs(void) {
    if (this->_pairs.size() < 2)
        return ;

    int check = 0;

    for (size_t i = 0; i + 1 < this->_pairs.size(); i++) {
        // std::vector<int>&   first = this->_pairs[i];
        // std::vector<int>&   second = this->_pairs[i + 1];

        if (this->_pairs[i][0] > this->_pairs[i + 1][0]) {
            int tmp = this->_pairs[i][0];
            this->_pairs[i][0] = this->_pairs[i + 1][0];
            this->_pairs[i + 1][0] = tmp;
            
            tmp = this->_pairs[i][1];
            this->_pairs[i][1] = this->_pairs[i + 1][1];
            this->_pairs[i + 1][1] = tmp;
            // check = 1;
        }

        // if (first[0] > second[0]) {
        //     tmp = first[0];
        //     first[0] = second[0];
        //     second[0] = tmp;
        //     check = 1;
        // }
        // if (first[1] > second[1]) {
        //     tmp = first[1];
        //     first[1] = second[1];
        //     second[1] = tmp;
        //     check = 1;
        // }
    }
    if (check)
        this->sortPairs();
}

void    SortVector::createChains(void) {
    for (size_t i = 0; i < this->_pairs.size(); i++) {
        this->_main.push_back(this->_pairs[i][0]);
        this->_pend.push_back(this->_pairs[i][1]);
    }
    this->_pairs.clear();

    if (this->_lastElement != -1)
        this->_pend.push_back(this->_lastElement);

    this->_main.insert(this->_main.begin(), *this->_pend.begin());
    this->_pend.erase(this->_pend.begin());
}

void    SortVector::insertion(void) {
    if (this->_pend.size() == 0)
        return ;
    
    int element = *this->_pend.begin();
    this->_pend.erase(this->_pend.begin());
    for (std::vector<int>::iterator it = this->_main.begin(); it != this->_main.end(); it++) {
        if (*it > element) {
            this->_main.insert(it, element);
            break ;
        }
    }
    this->insertion();
}

SortVector::SortVector() {}

SortVector::SortVector(std::list<int>::iterator begin, std::list<int>::iterator end) {
    for (; begin != end; begin++)
        this->_vector.push_back(*begin);
    
    this->_lastElement = this->getLastElement();
    this->convertToPairs();
    
    for (size_t i = 0; i < this->_pairs.size(); i++) {
        int first   = this->_pairs[i][0];
        int second  = this->_pairs[i][1];

        if (first < second) {
            this->_pairs[i][0] = second;
            this->_pairs[i][1] = first;
        }
    }
    
    this->sortPairs();
    this->createChains();
    this->insertion();
    
    // just print all vectors for show result and show how the code work
    std::cout << "Pairs: ";
    for (size_t i = 0; i < this->_pairs.size(); i++) {
        std::cout << "[" << this->_pairs[i][0] << " ";
        std::cout << this->_pairs[i][1] << "] ";
    } std::cout << '\n';
    
    std::cout << "main: ";
    for (size_t i = 0; i < this->_main.size(); i++)
        std::cout << this->_main[i] << ' ';
    std::cout << '\n';
    
    std::cout << "pend: ";
    for (size_t i = 0; i < this->_pend.size(); i++)
        std::cout << this->_pend[i] << ' ';
    std::cout << '\n';
}

SortVector::SortVector(const SortVector & src) { *this = src; }

SortVector::~SortVector() {}

SortVector &    SortVector::operator = (const SortVector & rhs) {
    (void)rhs;
    return *this;
}