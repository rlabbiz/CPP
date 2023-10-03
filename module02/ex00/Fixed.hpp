/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:45:23 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/10/02 13:18:04 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed {
private:
    int                 fixedPoint;
    static const int    fractional = 8;

public:
    Fixed();
    ~Fixed();
    Fixed(Fixed &tmp);
    Fixed&  operator = (const Fixed& next);
    int getRawBits(void) const;
    void setRawBits(int const raw);
};