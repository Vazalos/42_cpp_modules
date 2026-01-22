/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:34:57 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/13 11:02:06 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap A("Dynamo");
    DiamondTrap B("Flash");
    DiamondTrap C;
    DiamondTrap D(A);
    C = B;
    std::cout << '\n';
    
    A.attack("injustice itself");
    B.beRepaired(100);
    C.takeDamage(500);
    std::cout << '\n';

    A.guardGate();
    B.highFivesGuys();
    C.attack("nothing");
    D.highFivesGuys();
    std::cout << '\n';
    
    A.whoAmI();
    B.whoAmI();
    C.whoAmI();
    D.whoAmI();
    std::cout << '\n';
}