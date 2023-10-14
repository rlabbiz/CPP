/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:22:39 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/11 10:37:19 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
protected:
    std::string ideas[100];

public:
    Brain();
    // Brain(std::string   ideas[100]);
    Brain(const Brain &tmp);
    ~Brain();

    Brain &operator = (const Brain &next);

};

#endif