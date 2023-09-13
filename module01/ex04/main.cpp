/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:25:30 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/12 20:55:53 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int ac, char **av){
	if (ac != 4){
		std::cout << "bad arguments" << '\n';
		return 1;
	}
	std::string		line;
	std::ifstream	file(av[1], std::ios::in | std::ios::out);
	std::ofstream	newFile;

	newFile.open("newFile.txt");
	if (!newFile.is_open()){
		std::cout << "can't open the new file." << '\n';
		return 1;
	}
	while (std::getline(file, line)){
		std::cout << line << '\n';
		if (line == av[2])
			newFile << av[3] << '\n';
		else
			newFile << line << '\n';
	}
	//std::cout << file << '\n';
}
