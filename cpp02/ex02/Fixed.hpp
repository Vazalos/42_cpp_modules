/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:52:04 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/09 15:01:46 by david-fe         ###   ########.fr       */
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
    
    bool operator>( const Fixed& ) const;
    bool operator<( const Fixed& ) const;
    bool operator>=( const Fixed& ) const;
    bool operator<=( const Fixed& ) const;
    bool operator==( const Fixed& ) const;
    bool operator!=( const Fixed& ) const;

    Fixed operator+( const Fixed& ) const;
    Fixed operator-( const Fixed& ) const;
    Fixed operator*( const Fixed& ) const;
    Fixed operator/( const Fixed& ) const;

    Fixed& operator++( void ); //prefix increment
    Fixed operator++( int ); //postfix increment
    Fixed& operator--( void ); //prefix decrement
    Fixed operator--( int ); //postfix decrement

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream&, const Fixed&);

# endif