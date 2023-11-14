/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:07:12 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/13 11:54:08 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string _name) : name(_name), grade(150) { }

Bureaucrat::Bureaucrat(int _grade) : name("default") {
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = _grade;
}

Bureaucrat::Bureaucrat(int _grade, std::string _name) : name(_name) {
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = _grade;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name) {
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & tmp) : name(tmp.getName()) {
    *this = tmp;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat & next) {
    this->grade = next.grade;
    return *this;
}

std::string Bureaucrat::getName(void) const {
    return this->name;
}

int Bureaucrat::getGrade(void) const {
    return this->grade;
}

void    Bureaucrat::incrementGrade(void) {
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade -= 1;
}

void    Bureaucrat::decrementGrade(void) {
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade += 1;
}

void    Bureaucrat::signForm(Form & form) {
    try {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << '\n';
    } catch (std::exception & e) {
        std::cout << this->name << " could't sign " << form.getName() << " because " << e.what() << '\n';
    }
}

std::ostream & operator << (std::ostream & out, const Bureaucrat & b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}
