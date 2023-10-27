/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:07:24 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/27 15:53:16 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"

int main(void) {
    try
	{
		Form *Form;
		Bureaucrat bureaucrat("Bureaucrat", 2);
		ShrubberyCreationForm shrubberycreationform;
		RobotomyRequestForm robotomyrequestform("shit");
		PresidentialPardonForm presidentialpardonform("reda");
		
		Form = &shrubberycreationform;
		Form->beSigned(bureaucrat);
		Form->execute(bureaucrat);

		Form = &robotomyrequestform;
		Form->beSigned(bureaucrat);
		Form->execute(bureaucrat);

		Form = &presidentialpardonform;
		Form->beSigned(bureaucrat);
		Form->execute(bureaucrat);
		bureaucrat.executeForm(shrubberycreationform);
		bureaucrat.executeForm(robotomyrequestform);
		bureaucrat.executeForm(robotomyrequestform);

		bureaucrat.executeForm(presidentialpardonform);

		std::cout << shrubberycreationform << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}