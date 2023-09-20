/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:16:00 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/15 15:14:30 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

std::string get_line(std::string line);

class Contact{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	darkestSecret;
	std::string	phoneNumber;

public:
	std::string	printTenCharacter(std::string str);
	void		setFirst(std::string);
	void		setLast(std::string);
	void		setNick(std::string);
	void		setDarkest(std::string);
	void		setPhone(std::string);

	void		displayContact(void);
	void		search(int index);
};

#endif