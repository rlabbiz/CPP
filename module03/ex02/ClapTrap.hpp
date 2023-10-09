/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:41:10 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/09 11:57:23 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap {
protected:
    std::string name;
    int         hitPoint;
    int         energyPoint;
    int         attackDamage;

public:
    ClapTrap();
    ClapTrap(std::string str);
    ClapTrap(const ClapTrap &tmp);
    ~ClapTrap();
    
    ClapTrap&    operator = (const ClapTrap &next);
    
    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

    void    showInfo(void);
};
