/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:26:38 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/27 15:53:27 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("default",25, 5), _target("default"){}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target + "_form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : Form(src.getTarget() + "_form", 25, 5), _target(src.getTarget()) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm & PresidentialPardonForm::operator = (PresidentialPardonForm const & rhs) {
    (void)rhs;
    return *this;
}

std::string PresidentialPardonForm::getTarget(void) const { return this->_target; }


void    PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        return ;
    if (executor.getGrade() > this->getGradeToExecute())
        throw Form::GradeTooLowException();
    else
        std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << '\n';
}
