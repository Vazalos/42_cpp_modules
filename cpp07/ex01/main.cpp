/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:38:33 by david-fe          #+#    #+#             */
/*   Updated: 2026/03/06 12:14:46 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    std::string strArray[4] = {"Hi", "I", "am", "Bob"};
    int intArray[5] = {0, -1, 12, 340, 999};
    
    Iter(strArray, 4, printStr);
    std::cout << '\n';
    Iter(strArray, 4, printAny);
    std::cout << '\n';
    
    Iter(intArray, 5, printAny);
    std::cout << '\n';
    Iter(intArray, 5, incrementN);
    std::cout << '\n';
    Iter(intArray, 5, printAny);
    std::cout << '\n';
    Iter(intArray, 5, incrementAny);
    std::cout << '\n';
    Iter(intArray, 5, printAny);
}