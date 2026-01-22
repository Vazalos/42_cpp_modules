/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:58:38 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/09 15:18:16 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << '\n';

    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    
    std::cout << '\n' << "[ADDITIONAL TESTS]" << '\n';

    Fixed c(42.42f);
    Fixed res;
    Fixed const d( 2 );
    
    std::cout << a << " < " << c << " = " << (a < c) << std::endl;
    std::cout << d << " >= " << b << " = " << (a >= c) << std::endl;
    std::cout << d << " == " << d << " = " << (d == d) << std::endl;
    std::cout << c << " / " << a << " = " << (c / a) << std::endl;
    std::cout << c << " * " << a << " = " << (c * a) << std::endl;
    std::cout << c << " - " << a << " = " << (c - a) << std::endl;
    std::cout << b << " + " << b << " = " << (b + b) << std::endl;
    std::cout << b << " * " << d << " = " << (b * d) << std::endl;
    
    std::cout << "biggest between " << a << " and " << c << " is "
        << Fixed::max( a, c ) << std::endl;
    std::cout << "biggest between " << b << " and " << d << " is "
        << Fixed::max( b, d ) << std::endl;
    std::cout << "smallest between " << a << " and " << c << " is "
        << Fixed::max( a, c ) << std::endl;
    std::cout << "smallest between " << b << " and " << d << " is "
        << Fixed::max( b, d ) << std::endl;
    
    return 0;
}


