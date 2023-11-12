/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:24:16 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/07 12:09:19 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {

    if (ac < 2)
        return 1;
    ScalarConverter convert;

    convert.convert(av[1]);
    std::cout << convert;
    return 0;
}
