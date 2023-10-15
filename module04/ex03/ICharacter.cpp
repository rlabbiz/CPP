/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:01:10 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/14 22:01:11 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.cpp"

ICharacter::ICharacter() { std::cout << "ICharacter: Default constructor called." << '\n'; }

ICharacter::ICharacter(ICharacter const & tmp) {
    std::cout << "ICharacter: Copy constructor called." << '\n';
    *this = tmp;
}

ICharacter::~ICharacter() { std::cout << "ICbaracter:: Destructor called." << '\n'; }

