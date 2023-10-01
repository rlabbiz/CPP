/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:45:23 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/29 16:40:35 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed {
private:
    int                 fixedPoint;
    static const int    fractional = 8;

public:
    Fixed();
    ~Fixed();

    Fixed&    operator=(const Fixed& next);

    Fixed(const int raw);
    Fixed(const float raw);
    Fixed(const Fixed &tmp);

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat( void) const;
    int     toInt(void) const;
};

std::ostream    &operator << (std::ostream &out, Fixed const &curr); 
