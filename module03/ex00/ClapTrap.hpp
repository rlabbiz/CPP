/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:41:10 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/02 15:23:44 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap {
private:
    std::string name;
    int    hitPoint;
    int    energyPoint;
    int    attackDamage;

public:
    ClapTrap();
    ClapTrap(std::string str);
    ClapTrap(const ClapTrap &tmp);
    ~ClapTrap();
    
    ClapTrap&    operator = (const ClapTrap &next);
    
    int    getHitPoint(void) const;
    int    getEnergyPoint(void) const;
    int    getAttackDamage(void) const;

    void    setHitPoint(int amout);
    void    setEnergyPoint(int amout);
    void    setAttackDamage(int amout);
    
    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

    void    showInfo(void);
};
