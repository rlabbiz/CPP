/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:55:48 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/15 15:21:16 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::Search(void){
	int	i;
	
	i = 0;
	while (i < 8){
		contact[i].search(i);
		i++;
	}
}

void	PhoneBook::DisplayContact(void){
	std::string index_str;
    int         index_int;
    
    index_str = get_line("Index: ");
	if (index_str.empty())
		return ;
    if ((index_str[0] && std::isalpha(index_str[0])) || index_str.length() > 1)
        return ;
	index_int = index_str[0] - 48;
	if (index_int < 0 || index_int > 7)
		return ;
	contact[index_int].displayContact();
}

int	PhoneBook::insertData(int index){
	std::string	first, last, nick, darkest, phone;

	first	= get_line("First Name: ");
	if (first.empty())
		return 0;
	last	= get_line("Last Name: ");
	if (last.empty())
		return 0;
	nick 	= get_line("Nick Name: ");
	if (nick.empty())
		return 0;
	phone	= get_line("Phone Number: ");
	if (phone.empty())
		return 0;
	darkest	= get_line("Darkest Secret: ");
	if (darkest.empty())
		return 0;

	contact[index].setFirst(first);
	contact[index].setLast(last);
	contact[index].setNick(nick);
	contact[index].setDarkest(darkest);
	contact[index].setPhone(phone);
	return 1;
}