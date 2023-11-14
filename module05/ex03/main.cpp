/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:07:24 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/14 11:37:59 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int main(void) {
	Form* rrf;
	try 
	{
		Intern someRandomIntern;
		rrf = someRandomIntern.makeForm("presidentia", "Bender");
		if (!rrf)
			return 1;
		Bureaucrat bur(1);
		rrf->beSigned(bur);
		rrf->execute(bur);
	} 
	catch (std::exception & e) 
	{
		std::cout << e.what() << '\n';
	}
	delete rrf;
	return (0);
}
