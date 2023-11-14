/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:07:44 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/13 11:06:56 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
    try {
        Bureaucrat bureau("bureaucrat", 1);
        std::cout << bureau << '\n';
        bureau.decrementGrade();
        std::cout << bureau << '\n';
        bureau.incrementGrade();
        std::cout << bureau << '\n';
    } catch (std::exception & e) {
        std::cout << e.what() << '\n';
    }
}