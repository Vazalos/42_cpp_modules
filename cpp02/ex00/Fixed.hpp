/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:07:49 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/09 14:08:38 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed 
{
private:
    int val;
    static const int fractBits = 8;
public:
    Fixed();
    Fixed( const Fixed& );
    Fixed& operator=( const Fixed& );
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

# endif