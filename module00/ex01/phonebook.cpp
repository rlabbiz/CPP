/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:55:48 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/09 18:39:21 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string	get_line(std::string str){
	std::string	line;

	std::cout << str;
	std::getline(std::cin, line);
	while (line.empty()){
		std::cout << str;
		std::getline(std::cin, line);
	}
	return (line);
}

void	insertData(PhoneBook *phoneBook, int index){
	phoneBook->contact[index].addContact(
				get_line("First name: "),
				get_line("Last name: "),
				get_line("Nick name: "),
				get_line("Phone number: "),
				get_line("Darkest secret: ")
			);
}

void	searchOfContact(PhoneBook *phoneBook){
	phoneBook->Search();
	phoneBook->DisplayContact();
}

int main(void){
	std::string	line;
	PhoneBook	phoneBook;
	int			index;

	index = 0;
	while (std::cin){
		std::cout << "Prompot: ";
		getline(std::cin, line);
		if (line == "EXIT")
			exit(0);
		if (line == "ADD"){
			insertData(&phoneBook, index);
			index++;
		}
		else if (line == "SEARCH")
			searchOfContact(&phoneBook);
		if (index == 8)
			index = 0;
	}
}
