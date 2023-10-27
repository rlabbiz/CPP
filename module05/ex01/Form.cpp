/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:08:45 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/26 13:53:22 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _gradeToSigned(50), _gradeToExecute(10), _isSigned(false) { }

Form::Form(std::string name) : _name(name), _gradeToSigned(50), _gradeToExecute(10), _isSigned(false) { }

Form::Form(std::string name, int gradeToSigned) : _name(name), _gradeToSigned(gradeToSigned), _gradeToExecute(10), _isSigned(false) {
    if (gradeToSigned < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSigned > 150)
        throw Form::GradeTooLowException();
}

Form::Form(std::string name, int gradeToSigned, int gradeToExecute) : _name(name), _gradeToSigned(gradeToSigned), _gradeToExecute(gradeToExecute), _isSigned(false) {
    if (gradeToSigned < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSigned > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form & src) : _name(src.getName()), _gradeToSigned(src.getGradeToSigned()), _gradeToExecute(src.getGradeToExecute()), _isSigned(src.getIsSigned()) {
    // *this = src;
}

Form::~Form() { }

Form & Form::operator = (const Form & rhs) {
    this->_isSigned = rhs.getIsSigned();
    return *this;
}

bool        Form::getIsSigned(void) const { return this->_isSigned; }
int         Form::getGradeToExecute(void) const { return this->_gradeToExecute; }
int         Form::getGradeToSigned(void) const { return this->_gradeToSigned; }
std::string Form::getName(void) const { return this->_name; }

void    Form::beSigned(Bureaucrat & bureaucrat) {
    if (this->_gradeToSigned >= bureaucrat.getGrade())
        this->_isSigned = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream & operator << (std::ostream & out, const Form & src) {
    out << "Form: " << src.getName() << ", Grade to singed is " << src.getGradeToSigned() << " and Grade to execute is " << src.getGradeToExecute() << " ";
    if (src.getIsSigned())
        out << "(Is aready singed).";
    else
        out << "(Is not singed yet).";
    return out;
}