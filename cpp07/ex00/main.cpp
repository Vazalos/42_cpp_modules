/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:10:32 by david-fe          #+#    #+#             */
/*   Updated: 2026/03/05 17:14:58 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main()
{
    std::cout << '\n' << "PROVIDED EXAMPLE" << '\n';
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    

    
    std::cout << '\n' << "ADDITIONAL TESTS" << '\n';
    float A = 10.0;
    float B = 9.9999;
    char C = 'c';
    char D = 'd';
    bool E = true;
    bool F = false;
    std::string G = "goodbye";
    std::string H = "hello";

    std::cout << '\n' << "SWAPS" << '\n';
    //A & B
    std::cout << "A = " << A << "; B = " << B << '\n'; 
    swap(A,B);
    std::cout << "A = " << A << "; B = " << B << "\n\n";
    //C & D
    std::cout << "C = " << C << "; D = " << D << '\n'; 
    swap(C,D);
    std::cout << "C = " << C << "; D = " << D << "\n\n";
    //E & F
    std::cout << "E = " << E << "; F = " << F << '\n'; 
    swap(E,F);
    std::cout << "E = " << E << "; F = " << F << "\n\n";
    //G & H
    std::cout << "G = " << G << "; H = " << H << '\n'; 
    swap(G,H);
    std::cout << "G = " << G << "; H = " << H << '\n';
    

    std::cout << '\n' << "MIN" << '\n';
    //A & B
    std::cout << "min of " << A << " and " << B << " is " << min(A,B) << "\n\n";
    //C & D
    std::cout << "min of " << C << " and " << D << " is " << ::min(C,D) << "\n\n";
    //E & F
    std::cout << "min of " << E << " and " << F << " is " << min(E,F) << "\n\n";
    //G & H
    std::cout << "min of " << G << " and " << H << " is " << ::min(G,H) << "\n\n";

    
    std::cout << '\n' << "MAX" << '\n';
    //A & B
    std::cout << "max of " << A << " and " << B << " is " << max(A,B) << "\n\n";
    //C & D
    std::cout << "max of " << C << " and " << D << " is " << ::max(C,D) << "\n\n";
    //E & F
    std::cout << "max of " << E << " and " << F << " is " << max(E,F) << "\n\n";
    //G & H
    std::cout << "max of " << G << " and " << H << " is " << ::max(G,H) << "\n\n";
}