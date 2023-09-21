/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:23:44 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/20 22:46:14 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie{
private:
	std::string	name;

public:
	Zombie(std::string str);
	~Zombie(void);

	void	announce(void);
	void	randomChump(std::string str);
	Zombie	*newZombie(std::string str);
};

#endif
