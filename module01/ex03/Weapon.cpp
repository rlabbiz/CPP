/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:12:25 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/21 00:13:01 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

Weapon::Weapon(std::string	str) :	type(str) {}

Weapon::~Weapon(void) {}

void	Weapon::setType(std::string str) { type = str; }

std::string	Weapon::getType(void) const { return type; }
