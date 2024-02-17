/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:18:49 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/12/01 22:55:11 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::printTenCharacter(std::string str){
	std::string	tmp;

	if (str.length() > 10){
		tmp = str.substr(0, 9);
		tmp.push_back('.');
		return(tmp);
	} else {
		return str;
	}
}

void		Contact::setFirst(std::string str) { firstName = str; }
void		Contact::setLast(std::string str) { lastName = str; }
void		Contact::setNick(std::string str) { nickName = str; }
void		Contact::setDarkest(std::string str) { darkestSecret = str; }
void		Contact::setPhone(std::string str) { phoneNumber = str; }

void	Contact::search(int index){
    if (this->firstName.empty())
        return ;
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << printTenCharacter(firstName) << "|";
	std::cout << std::setw(10) << printTenCharacter(lastName) << "|";
	std::cout << std::setw(10) << printTenCharacter(nickName) <<"|";
	std::cout << std::endl;
}

void	Contact::displayContact(void){
    if (this->firstName.empty())
        return ;
	std::cout << "\tfirst name: " << firstName << std::endl;
	std::cout << "\tlast name: " << lastName << std::endl;
	std::cout << "\tnick name: " << nickName << std::endl;
	std::cout << "\tphone number: " << phoneNumber << std::endl;
	std::cout << "\tdarkest secret: " << darkestSecret << std::endl;
}