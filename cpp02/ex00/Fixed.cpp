/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:07:23 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/03 15:10:16 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    val = 0;
    std::cout << "Default constructor called" << '\n';
}

Fixed::Fixed(const Fixed& origFixed)
    :val(origFixed.val)
{
    std::cout << "Copy constructor called" << '\n';
    //operator=(origFixed); //for use without list init
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
    