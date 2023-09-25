/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:45:23 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/25 15:21:16 by rlabbiz          ###   ########.fr       */
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
    
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);

    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
    
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat( void) const;
    int     toInt(void) const;
    
};

std::ostream    &operator<<(std::ostream &out, Fixed const &curr); 
