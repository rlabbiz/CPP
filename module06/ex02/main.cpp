/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:51:58 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/11/08 15:49:53 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void) {
    A   a;
    B   b;
    C   c;

    identify(a);
    identify(b);
    identify(c);

    Base *  base1 = generate();
    Base *  base2 = generate();
    Base *  base3 = generate();

    identify(base1);
    identify(base2);
    identify(base3);

    delete base1;
    delete base2;
    delete base3;
}