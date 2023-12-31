/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:03:14 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/27 15:42:51 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class	Weapon {
private:
	std::string	type;

public:
	Weapon(std::string str);
	~Weapon(void);
	void		setType(std::string	str);
	const std::string	&getType(void) const;
};

#endif
