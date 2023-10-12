/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:44:26 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/11 11:32:54 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA {
private:
	std::string	name;
	Weapon		&wpn;

public:
	HumanA(std::string str, Weapon &wp);
	~HumanA();
	void	attack(void);
	void	setWeapon(Weapon &wpn);
};

#endif
