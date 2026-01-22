/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:05:25 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/06 16:45:49 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ClapTrap A("Robbie");
    ScavTrap B("Borborygmus");
    ScavTrap C("Bolognese");
    std::cout << '\n';
    
    A.attack("a car");
    B.attack("an entire train");
    C.attack("Borborygmus");
    B.takeDamage(20);
    B.beRepaired(30);
    std::cout << '\n';

    B.attack("Robbie");
    A.takeDamage(20);
    A.beRepaired(5);
    std::cout << '\n';
    
    ScavTrap D ( B );
    ScavTrap E;
    E = C;
    std::cout << '\n';
    
    D.guardGate();
    E.guardGate();
    std::cout << '\n';
    
    return(0);
}