/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:53:02 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/27 15:53:10 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
#define Form_HPP

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
    virtual ~Form();

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

    virtual void    execute(Bureaucrat const & executor) const = 0;
    
};

std::ostream & operator << (std::ostream & out, const Form & src);

#endif
