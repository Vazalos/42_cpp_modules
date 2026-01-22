/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:14:19 by david-fe          #+#    #+#             */
/*   Updated: 2025/12/18 14:25:50 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    val = 0;
    std::cout << "Default constructor called" << '\n';
}

Fixed::Fixed( const int i )
{
    val = i << fractBits;
    std::cout << "Int constructor called" << '\n';
}

Fixed::Fixed( const float f )
{
    val = roundf(f * (1 << fractBits));
    std::cout << "Float constructor called" << '\n';
}

Fixed::Fixed(const Fixed& origFixed)
    :val(origFixed.val)
{
    std::cout << "Copy constructor called" << '\n';
}

Fixed& Fixed::operator=(const Fixed& origFixed)
{
    std::cout << "Copy assignment operator called" << '\n';
    if (this != &origFixed)
        val = origFixed.getRawBits();
    return(*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << '\n';
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << '\n';
    return(val);
}

void Fixed::setRawBits( int const raw )
{
    val = raw;
}

float Fixed::toFloat( void ) const
{
    return(static_cast<float>(val) / (1 << fractBits));
}

int Fixed::toInt( void ) const
{
    return(val >> fractBits);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixedToFloat)
{
    return(stream << fixedToFloat.toFloat());
}