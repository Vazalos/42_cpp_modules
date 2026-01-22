/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:08:12 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/22 15:30:35 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat A("Janet", 80);
    std::cout << A << '\n';
    Bureaucrat B("Connor", 100);
    std::cout << B << '\n';
    Bureaucrat C = B;
    std::cout << C << '\n';
    A = C;

    for (int i = 0; i < 10; i++)
        A.incrementGrade();    

    std::cout << A << '\n';
    std::cout << B << '\n';
    std::cout << C << '\n';
}