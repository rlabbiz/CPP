/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:22:19 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/18 22:58:56 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	get_line(std::string str){
	std::string	line;

	std::cout << str;
	std::getline(std::cin, line);
	return (line);
}


void	searchOfContact(PhoneBook *phoneBook){
	std::cout << "--------------------------------------------" << '\n';
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << "|" << std::endl;
	std::cout << "--------------------------------------------" << '\n';
	phoneBook->Search();
	std::cout << "--------------------------------------------" << '\n';
	phoneBook->DisplayContact();
}

int main(void){
	std::string	line;
	PhoneBook	phoneBook;
	int			index;
	int			check;

	index	= 0;
	check	= 0;
	while (std::cin){
		line = get_line("Prompot(ADD, SEARCH, EXIT): ");
		if (line == "EXIT")
			exit(0);
		if (line == "ADD")
		{
			index += phoneBook.insertData(index);
			check += index;
		}
		else if (line == "SEARCH" && check != 0)
			searchOfContact(&phoneBook);
		if (index == 8)
			index = 0;
	}
}
