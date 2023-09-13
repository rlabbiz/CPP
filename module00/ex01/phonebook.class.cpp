/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:02:35 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/10 11:01:46 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"


void    Contact::printTenCharacter(std::string str){
	std::string	tmp;

	if (str.length() > 10){
		tmp = str.substr(0, 9);
		tmp.push_back('.');
		std::cout << tmp;
		tmp.clear();
	} else {
		std::cout << str;
	}
}

void	Contact::addContact(
			std::string first,
			std::string last,
			std::string nick,
			std::string num,
			std::string dark
		){
	this->firstName		= first;
	this->lastName		= last;
	this->nickName		= nick;
	this->phoneNumber	= num;
	this->darkestSecret	= dark;
}

void	Contact::search(int index){
    if (this->firstName.empty())
        return ;
	std::cout << index << " | ";
	printTenCharacter(this->firstName);
	std::cout << " | ";
	printTenCharacter(this->lastName);
	std::cout << " | ";
	printTenCharacter(this->nickName);
	std::cout << " | ";
	std::cout << std::endl;
}

void	Contact::displayContact(void){
    if (this->firstName.empty())
        return ;
	std::cout << "\tfirst name: " << this->firstName << std::endl;
	std::cout << "\tlast name: " << this->lastName << std::endl;
	std::cout << "\tnick name: " << this->nickName << std::endl;
	std::cout << "\tphone number: " << this->phoneNumber << std::endl;
	std::cout << "\tdarkest secret: " << this->darkestSecret << std::endl;
}

void	PhoneBook::Search(void){
	int	i;
	
	i = 0;
	while (i < 8){
		this->contact[i].search(i);
		i++;
	}
}

void	PhoneBook::DisplayContact(void){
	std::string index_str;
    int         index_int;
    
    index_str = get_line("Index: ");
    while (index_str[0] && std::isalpha(index_str[0]))
        index_str = get_line("Index (just number): ");
    index_int = std::atoi(index_str.c_str());
	while (index_int < 0 || index_int > 7){
		index_str = get_line("Index (0:7): ");
        index_int = std::atoi(index_str.c_str());
	}
	this->contact[index_int].displayContact();
}