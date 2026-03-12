/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:02:36 by david-fe          #+#    #+#             */
/*   Updated: 2026/03/10 17:16:36 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
    Array<int> A(3);
    Array<int> B(5);
    Array<int> C(A);
    
    std::cout << "FIRST TRY\n";
    try
    {
        for(unsigned int i = 0; i < 5; i++)
            std::cout << A[i] << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "SECOND TRY\n";
    try
    {
        for(unsigned int i = 0; i < B.size(); i++)
        {
            B[i] = i;
            std::cout << B[i] << "\n";
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "THIRD TRY\n";
    try
    {
        A = B;
        for(unsigned int i = 0; i < A.size(); i++)
            std::cout << A[i] << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "FOURTH TRY\n";
    try
    {
        for(unsigned int i = 0; i < C.size(); i++)
            std::cout << C[i] << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}