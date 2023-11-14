/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:26:47 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/14 11:23:15 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("default", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(target + "_form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : Form(src.getTarget(), 72, 45), _target(src.getTarget()) { }

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm & RobotomyRequestForm::operator = (RobotomyRequestForm const & rhs) {
    (void)rhs;
    return *this;
}

std::string RobotomyRequestForm::getTarget(void) const { return this->_target; }

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    std::cout << this->_target << ": MBAAAAZZZZ" << '\n';
    if (!this->getIsSigned())
        return ;
    if (executor.getGrade() > this->getGradeToExecute())
        throw Form::GradeTooLowException();
    else {
        static int num;
        if (num % 2 == 0){
            std::cout << this->_target << " has been robotomized successfully 50\% of the time" << '\n';
        }else {
            std::cout << this->_target << " robotomy failed" << '\n';
        }
        num++;
    }
}