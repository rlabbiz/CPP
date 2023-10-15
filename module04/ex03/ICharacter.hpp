/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:56:28 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/14 22:15:24 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "main.hpp"

class ICharacter
{
protected:
    std::string name;

public:
    virtual ICharacter();
    virtual ICharacter(ICharacter const & tmp);
    virtual ~ICharacter();

    ICharacter  operator = (ICharacter const & next);

    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;

};
#endif