/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:34:25 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/12 16:34:59 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " is created. Cool I guess?" << '\n';
}

ScavTrap::ScavTrap(std::string newName) : ClapTrap(newName)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " is created. Cool I guess?" << '\n';
}

ScavTrap::ScavTrap(const ScavTrap& origScav) : ClapTrap(origScav)
{
    name = origScav.name;
    hitPoints = origScav.hitPoints;
    energyPoints = origScav.energyPoints;
    attackDamage = origScav.attackDamage;
    std::cout << "ScavTrap " << name << " was cloned, that's probably no good."
    << '\n';
}

ScavTrap& ScavTrap::operator=(const ScavTrap& origScav)
{
    std::string oldName = name;
    if (this != &origScav)
    {
        name = origScav.name;
        hitPoints = origScav.hitPoints;
        energyPoints = origScav.energyPoints;
        attackDamage = origScav.attackDamage;    
        std::cout << "ScavTrap " << oldName << " was forcefully equalized to " << name
            << ", didn't like it." << '\n';
    }
    return(*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << name << " is sent to the landfill. Oh well." << '\n';
}

void ScavTrap::attack(const std::string& target)
{
    if (hitPoints > 0 && energyPoints > 0)
    {
        energyPoints--;
        std::cout << "ScavTrap " << name << " violently strikes " << target <<
            ", inflicting " << attackDamage << " points of massive damage!" << '\n';
    }
    else
        std::cout << "ScavTrap " << name << " is too wrecked to attack." << '\n';
}

void ScavTrap::guardGate(void)
{
    if (hitPoints > 0 && energyPoints > 0)
    {
        std::cout << "ScavTrap " << name << " has now entered Gatekeeper mode. "
            "You shall not pass!" << '\n';
    }
}
