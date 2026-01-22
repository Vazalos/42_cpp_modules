/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:57:41 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/12 17:20:56 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*Hit points (FragTrap)
  Energy points (ScavTrap)
  Attack damage (FragTrap)
  attack() (ScavTrap)*/

//ClapTrap constructor shows message only once

DiamondTrap::DiamondTrap() : name("Default")
{
  ClapTrap::name += "_clap_name";
  hitPoints = FragTrap::hitPoints;
  energyPoints = ScavTrap::energyPoints;
  attackDamage = FragTrap::attackDamage;
  std::cout << "DiamondTrap " << name << " is artistically assembled! " 
    "What a masterpiece!" << '\n';
}

DiamondTrap::DiamondTrap(std::string newName) : ClapTrap(newName + "_clap_name"),
  ScavTrap(newName + "_clap_name"), FragTrap(newName + "_clap_name"), name(newName)
{
  hitPoints = FragTrap::hitPoints;
  energyPoints = ScavTrap::energyPoints;
  attackDamage = FragTrap::attackDamage;
  std::cout << "DiamondTrap " << name << " is artistically assembled! " 
    "What a masterpiece!" << '\n';
}

DiamondTrap::DiamondTrap(const DiamondTrap& origDiamond) : ClapTrap(origDiamond), 
  ScavTrap(origDiamond), FragTrap(origDiamond), name(origDiamond.name)
{
  hitPoints = origDiamond.hitPoints;
  energyPoints = origDiamond.energyPoints;
  attackDamage = origDiamond.attackDamage;
  std::cout << "DiamondTrap " << name << " is rigorously replicated! " 
    "Shiny Twins!" << '\n';
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& origDiamond)
{
  std::string oldName = name;
  if(this != &origDiamond)
  {
    name = origDiamond.name;
    ClapTrap::name = origDiamond.ClapTrap::name;
    hitPoints = origDiamond.hitPoints;
    energyPoints = origDiamond.energyPoints;
    attackDamage = origDiamond.attackDamage;
    std::cout << "DiamondTrap " << oldName << " is retrofitted to match " << name
      << "'s beautiful blueprints! A mirror-polished reflection!" << '\n';
  }
  return(*this);
}

DiamondTrap::~DiamondTrap()
{
  std::cout << "DiamondTrap " << name << " was deviously deactivated! No one "
   "appreciates fine art nowadays..." << '\n';
}

void DiamondTrap::whoAmI()
{
    if (hitPoints > 0 && energyPoints > 0)
    {
        std::cout << "I, DiamondTrap " << name << ", am also known under the secret"
          " name of " << ClapTrap::name << '\n';
    }
}