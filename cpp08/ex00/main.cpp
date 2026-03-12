/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:49:24 by david-fe          #+#    #+#             */
/*   Updated: 2026/03/11 13:39:56 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
    int size = 5;
    int nums[] = {1, 3, 5, 7, 9};
    for(int i = 0; i < size; i++)
        std::cout << nums[i] << " ";
    std::cout << "\n";
    
    std::cout << "USING <VECTOR>" << '\n';
    std::vector<int> A(nums, nums + size); // element beyond last number
    
    try
    {
        std::cout << *(easyfind(A, 1)) << '\n';
        std::cout << *(easyfind(A, 9)) << '\n';
        std::cout << *(easyfind(A, 4)) << '\n'; // can't be found
        std::cout << *(easyfind(A, 1)) << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "USING <LIST>" << '\n';
    std::list<int> B(nums, nums + size);  // element beyond last number
    
    try
    {
        std::cout << *(easyfind(B, 3)) << '\n';
        std::cout << *(easyfind(B, 7)) << '\n';
        std::cout << *(easyfind(B, 'a')) << '\n'; // can't be found
        std::cout << *(easyfind(B, 3)) << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}