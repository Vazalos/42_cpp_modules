/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:13:44 by david-fe          #+#    #+#             */
/*   Updated: 2025/12/18 14:26:25 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <math.h>
# include <iomanip>
# include <stdio.h>

class Fixed 
{
private:
    int val;
    static const int fractBits = 8;
public:
    Fixed();
    Fixed( const int );
    Fixed( const float );
    Fixed( const Fixed& );
    Fixed& operator=( const Fixed& );
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream& operator<<(std::ostream&, const Fixed&);

# endif