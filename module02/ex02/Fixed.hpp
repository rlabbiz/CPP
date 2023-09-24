/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:45:23 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/24 14:50:14 by rlabbiz          ###   ########.fr       */
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

    void    operator=(const Fixed& next);
    
    bool    operator>(const Fixed& next);
    bool    operator<(const Fixed& next);
    bool    operator>=(const Fixed& next);
    bool    operator<=(const Fixed& next);
    bool    operator==(const Fixed& next);
    bool    operator!=(const Fixed& next);

    float   operator+(const Fixed& next);
    float   operator-(const Fixed& next);
    float   operator*(const Fixed& next);
    float   operator/(const Fixed& next);

    Fixed   operator++();
    Fixed   operator++(int);
    void    operator--();
    void    operator--(int);

    Fixed(const int raw);
    Fixed(const float raw);
    Fixed(const Fixed &tmp);

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat( void) const;
    int     toInt(void) const;

    
};

std::ostream    &operator<<(std::ostream &out, Fixed const &curr); 