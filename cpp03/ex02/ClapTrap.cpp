/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:34:11 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/12 16:28:40 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10),
    attackDamage(0)
{
    std::cout << "ClapTrap " << name << " is born! Oh joyous day!" << '\n';
}

ClapTrap::ClapTrap(std::string newName) : name(newName), hitPoints(10), 
    energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " is born! Oh joyous day!" << '\n';
}

ClapTrap::ClapTrap(const ClapTrap& OrigClap) : name(OrigClap.name),
    hitPoints(OrigClap.hitPoints), energyPoints(OrigClap.energyPoints), 
    attackDamage(OrigClap.attackDamage)
{
    std::cout << "ClapTrap " << name << " was cloned like some sort of "
        "interchangeable machine." << '\n';
}

ClapTrap& ClapTrap::operator=(const ClapTrap& origClap)
{
    std::string oldName = name;
    if (this != &origClap)
    {
        name = origClap.name;
        hitPoints = origClap.hitPoints;
        energyPoints = origClap.energyPoints;
        attackDamage = origClap.attackDamage;
        std::cout << "ClapTrap " << oldName << " was made equal to it's kin " 
            << name << ". But some are more equal than others!" << '\n';
    }
    return(*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << name << " is scrapped! Will anyone think of "
        "the robots!?" << '\n';
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints > 0 && energyPoints > 0)
    {
        energyPoints--;
        std::cout << "ClapTrap " << name << " attacks " << target <<
            ", causing " << attackDamage << " points of damage!" << '\n';
    }
    else
        std::cout << "ClapTrap " << name << " is unable to attack." << '\n';
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints > 0)
        hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;
    std::cout << "ClapTrap " << name << " took " << amount << " damage and is left with "
        << hitPoints << " hitpoints." << '\n';
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints > 0 && energyPoints > 0)
    {
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " repaired itself for " << amount << 
        " hitpoints and is now up to " << hitPoints << '\n';
    }
    else
        std::cout << "ClapTrap " << name << " is unable to repair itself." << '\n';
}

