/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:14:48 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/12/04 15:34:30 by rlabbiz          ###   ########.fr       */
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

std::list<int> &    getSequence(char **av) {
    std::string sequenceString = convertToString(av);
    if (!checkSequence(sequenceString)) {
        std::cerr << "Error" << '\n';
        exit(1);
    }
    std::stringstream stream(sequenceString);
    std::string word;
    while (stream >> word) {
        std::cout << word << '\n';
        
    }
    
    exit(1);
}
