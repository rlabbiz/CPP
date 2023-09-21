/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:16:42 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/20 23:50:51 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void){
	std::string	str			= "HI THIS IS BRAIN";
	std::string	*stringPTR	= &str;
	std::string	&stringREF	= str;

	std::cout << "Print the address" << '\n';
	std::cout << '\t' << "The memory address of the string variable: " << &str << '\n';
	std::cout << '\t' << "The memory address held by stringPTR: " << &stringPTR << '\n';
	std::cout << '\t' << "The memory address held by stringREF: " << &stringREF << '\n';

	std::cout << "Print the value" << '\n';
	std::cout << '\t' << "The value of the string variable: " << str << '\n';
	std::cout << '\t' << "The value pointed to by stringPTR: " << *stringPTR << '\n';
	std::cout << '\t' << "The value pointed to by stringREF: " << stringREF << '\n';
		
}
