/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:34:05 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/06 16:52:47 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap A("Don");
    FragTrap B("Zip");
    std::cout << '\n';
    
    A.attack("political instability in South Sudan");
    A.takeDamage(7);
    A.beRepaired(40);
    std::cout << '\n';
    
    FragTrap C ( A );
    C = B;
    std::cout << '\n';

    A.highFivesGuys();
    B.highFivesGuys();
    C.highFivesGuys();
    std::cout << '\n';
    
    return(0);
}