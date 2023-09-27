/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:41:10 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/25 22:04:25 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap {
private:
    std::string name;
    unsigned int    hitPoint        = 10;
    unsigned int    energyPoint     = 10;
    unsigned int    attackDamage    = 0;
public:
    ClapTrap();
    ClapTrap(std::string str);
    ~ClapTrap();
    ClapTrap&    operator = (ClapTrap &next);
    
    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
};
