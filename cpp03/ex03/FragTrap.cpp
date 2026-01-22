/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:41:04 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/12 16:34:46 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " is constructed. A neutral occurrence..." << '\n';
}

FragTrap::FragTrap(std::string newName) : ClapTrap(newName)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " is constructed. A neutral occurrence..." << '\n';
}

FragTrap::FragTrap(const FragTrap& origFrag) : ClapTrap(origFrag)
{
    name = origFrag.name;
    hitPoints = origFrag.hitPoints;
    energyPoints = origFrag.energyPoints;
    attackDamage = origFrag.attackDamage;
    std::cout << "FragTrap " << name << " was cloned, pretty ok."
    << '\n';
}

FragTrap& FragTrap::operator=(const FragTrap& origFrag)
{
    std::string oldName = name;
    if (this != &origFrag)
    {
        name = origFrag.name;
        hitPoints = origFrag.hitPoints;
        energyPoints = origFrag.energyPoints;
        attackDamage = origFrag.attackDamage;
        std::cout << "FragTrap " << oldName << " was equalled to " << name << ". This is "
            "deemed acceptable." << '\n';
    }
    return(*this);
}


FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << name << " is shipped to a scrapyard. Pity!" << '\n';
}

void FragTrap::highFivesGuys(void)
{
    if (hitPoints > 0 && energyPoints > 0)
    {
        std::cout << "FragTrap " << name << " distributes workplace-appropriate "
            "high-fives!" << '\n';
    }
}