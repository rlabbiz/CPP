/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:07:44 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/25 17:07:45 by rlabbiz          ###   ########.fr       */
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
        bureau.incrementGrade();
    } catch (std::exception & exx) {
        std::cout << exx.what() << '\n';
    }
}