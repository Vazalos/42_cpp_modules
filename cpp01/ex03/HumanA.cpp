/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:50:29 by david-fe          #+#    #+#             */
/*   Updated: 2025/11/04 14:05:33 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon& newWeaponRef) : name(newName), weapon(newWeaponRef){};

HumanA::~HumanA(void){};

void HumanA::setWeapon(Weapon& newWeapon)
{
    weapon = newWeapon;
}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << '\n';
}