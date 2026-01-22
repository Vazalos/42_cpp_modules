/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:05:25 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/06 15:05:18 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap A("Robbie");
    ClapTrap B("Clankina");
    ClapTrap C;
    ClapTrap D( B );
    
    std::cout << '\n';
    B.attack("a passing squirrel");
    std::cout << '\n';
    for (int i = 4; i > 0; i--)
    {
        A.attack("a foolish human");   
        if (i % 2 == 0)
            A.takeDamage(6);
    }
    std::cout << '\n';
    for (int j = 10; j > 0; j--)
        B.beRepaired(1);    
    std::cout << '\n';
    A.beRepaired(10);
    C = A;
    std::cout << '\n';
    
    return(0);
}