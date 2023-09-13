/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:56:06 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/09 19:53:06 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>

std::string get_line(std::string line);

class Contact{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	darkestSecret;
	std::string	phoneNumber;
	void	printTenCharacter(std::string str);
public:
	void	displayContact(void);
	void	search(int index);
	void	addContact(
				std::string first,
				std::string last,
				std::string nick,
				std::string num,
				std::string dark
			);
};

class PhoneBook{
public:
	Contact contact[8];
	void	Search(void);
	void	DisplayContact(void);
};

#endif
