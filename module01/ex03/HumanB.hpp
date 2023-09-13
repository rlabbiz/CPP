/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:04:36 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/12 17:09:19 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB {
private:
	std::string	name;
	Weapon		*wpn;

public:
	HumanB(std::string str);
	~HumanB();
	void	attack(void);
	void	setWeapon(Weapon &wpn);
};

#endif
