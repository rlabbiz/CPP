/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:07:15 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/26 13:56:08 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string   _name;
    const int           _gradeToSigned;
    const int           _gradeToExecute;
    bool                _isSigned;

public:
    Form();
    Form(std::string name);
    Form(std::string name, int gradeToSigned);
    Form(std::string name, int gradeToSinged, int gradeToExecute);
    Form(const Form & src);
    ~Form();

    Form & operator = (const Form & rhs);

    bool        getIsSigned(void) const ;
    int         getGradeToExecute(void) const ;
    int         getGradeToSigned(void) const ;
    std::string getName(void) const ;

    void    beSigned(Bureaucrat & bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char * what(void) const throw() { return "Form: grade too high"; }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char * what(void) const throw() { return "Form: grade too low"; }
    };
};

std::ostream & operator << (std::ostream & out, const Form & src);

#endif
