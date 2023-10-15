/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:29:20 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/14 22:27:56 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "main.hpp"

class AMateria
{
protected:
    std::string type;

public:

    AMateria();
    AMateria(std::string const & type);
    AMateria(AMateria const & tmp);
    ~AMateria();
    
    AMateria&   operator = (const AMateria & next);

    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif