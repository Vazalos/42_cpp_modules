/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:50:29 by david-fe          #+#    #+#             */
/*   Updated: 2025/11/04 14:02:00 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string newName) : name(newName)
{
    weapon = NULL;
};

HumanB::~HumanB(void){};

void HumanB::setWeapon(Weapon& newWeapon)
{
    weapon = &newWeapon;
}

void HumanB::attack()
{
    std::string weaponType;
    if (weapon != NULL)
        weaponType = (*weapon).getType();
    if (weaponType.empty())
        std::cout << name << " has no weapon to attack with, get rekt!" << '\n';
    else
        std::cout << name << " attacks with their " << weaponType << '\n';
}