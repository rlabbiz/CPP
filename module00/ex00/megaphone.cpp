/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:58:06 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/15 10:26:01 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	ft_toUpperStr(std::string str){
	int	i = 0;

	while (str[i]){
		std::cout << (char )toupper(str[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	int	i;
	if (ac <= 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
		return (1);
	}
	i = 1;
	while (av[i]){
		ft_toUpperStr(av[i]);
		i++;
	}
	std::cout << '\n';
	return (0);
}
