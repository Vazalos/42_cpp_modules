/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:14:24 by david-fe          #+#    #+#             */
/*   Updated: 2026/03/12 11:36:14 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
    Span sp = Span(5);
    
    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(99);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
       
    std::cout << "Additional Test #1\n";

    unsigned int size = 10000;
    Span big(size);
    std::vector<int> source;
    
    for (unsigned int i = 0; i < size + 1; i++)
    {
        source.push_back(rand() % 10001);
        std::cout << source[i] << " ";
    }
    
    try
    {
        big.addMultiNumbers(source.begin(), source.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << '\n';
    std::cout << big.shortestSpan() << std::endl;
    std::cout << big.longestSpan() << std::endl;

    std::cout << "Additional Test #2\n";

    Span small(3);
    
    small.addNumber(10);
    
    try
    {
        std::cout << small.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << small.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    small.addNumber(5); 
    std::cout << small.longestSpan() << std::endl;
    std::cout << small.shortestSpan() << std::endl;
    int randN = rand() % 5;
    std::cout << "adding " << randN << '\n';
    small.addNumber(randN);
    std::cout << small.longestSpan() << std::endl;
}