/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:07:24 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/13 12:40:55 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    try {
        Bureaucrat  bureau("reda", 1);
        Form        form("formName", 5);
        bureau.signForm(form);
    } catch (std::exception & e) {
        std::cout << e.what() << '\n';
    }
}