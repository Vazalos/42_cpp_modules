/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:08:12 by david-fe          #+#    #+#             */
/*   Updated: 2026/02/25 13:31:37 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << '\n' << "Valid Test" << '\n';
    try
    {
        Bureaucrat A("Ariel", 9);
        std::cout << A << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << '\n' << "Invalid Test" << '\n';
    try
    {
        Bureaucrat B("Bill", 151);
        std::cout << B << '\n';
    }
    catch(const std::exception& f)
    {
        std::cerr << f.what() << '\n';
    }

    std::cout << '\n' << "Grade Change Exception Test" << '\n';
    Bureaucrat C("Connor", 2);
    Bureaucrat D;
    std::cout << '\n';
    try
    {
        std::cout << C << '\n';
        C.incrementGrade();
        std::cout << C << '\n';
        C.incrementGrade();
        std::cout << C << '\n';
    }
    catch(const std::exception& g)
    {
        std::cerr << g.what() << '\n';
    }
    std::cout << C << '\n';

    std::cout << '\n' << "= Operator Test" << '\n';
    try
    {
        std::cout << D << '\n';
        D = C;
        std::cout << D << '\n';
    }
    catch(const std::exception& h)
    {
        std::cerr << h.what() << '\n';
    }

    std::cout << '\n' << "Grade Set Test" << '\n';
    try
    {
        D.setGrade(50);
        std::cout << D << '\n';
    }
    catch(const std::exception& h)
    {
        std::cerr << h.what() << '\n';
    }
}