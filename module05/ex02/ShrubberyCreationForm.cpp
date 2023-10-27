/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:14:15 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/27 15:53:43 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("default", 145, 137), _target("default") { }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target + " Form", 145, 137), _target(target) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src) : Form("default", 145, 137) {
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() { }

ShrubberyCreationForm & ShrubberyCreationForm::operator = (const ShrubberyCreationForm & rhs) {
    this->_target = rhs.getTarget();
    return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const { return this->_target; }

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw Form::GradeTooLowException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw Form::GradeTooLowException();
    std::ofstream outFile(std::string(this->_target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);
    if (!outFile.is_open()){
        std::cout << this->_target << ", cant open file " << '\n';
        return ;
    }
    outFile << "       _-_\n";
	outFile << "    /~~   ~~\\\n";
	outFile << " /~~         ~~\\\n";
	outFile << "{               }\n";
	outFile << " \\  _-     -_  /\n";
	outFile << "   ~  \\\\ //  ~\n";
	outFile << "_- -   | | _- _\n";
	outFile << "  _ -  | |   -_\n";
	outFile << "      // \\\\\n";
	outFile.close();
}

