/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:07:07 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/26 14:09:47 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat {
private:
    const std::string   name;
    int                 grade;
public:
    Bureaucrat();
    Bureaucrat(std::string _name);
    Bureaucrat(int _grade);
    Bureaucrat(std::string _name, int _grade);
    Bureaucrat(int _grade, std::string _name);
    Bureaucrat(const Bureaucrat & tmp);
    ~Bureaucrat();

    Bureaucrat & operator = (const Bureaucrat & next);

    std::string getName(void) const ;
    int         getGrade(void) const ;

    void    incrementGrade(void);
    void    decrementGrade(void);

    void    signForm(Form & form);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char * what() const throw() { return "Bureaucrat: Grade too high"; };
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char * what() const throw() { return "Bureaucrat: Grade too low"; };
    };

};

std::ostream & operator << (std::ostream & out, const Bureaucrat & b);

#endif