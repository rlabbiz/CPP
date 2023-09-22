/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:45:23 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/22 17:18:38 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed {
private:
    int                 fixedPoint;
    float               floatFixedPoint;
    bool                isFloat;
    static const int    fractional = 8;

public:
    Fixed();
    ~Fixed();
    operator float() const {
        // std::cout << "Copy assignment operator called" << '\n';
        if (isFloat == true)
            return floatFixedPoint;
        return fixedPoint;
    }
    
    Fixed(const int raw);
    Fixed(const float raw);
    Fixed(const Fixed &tmp);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat( void) const;
    int     toInt(void) const;
    
};