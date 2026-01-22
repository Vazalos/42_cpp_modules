/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:09:47 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/31 14:56:38 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void){};

Weapon::Weapon(std::string newType)
{
    type = newType;
}

Weapon::~Weapon(void){};

const std::string& Weapon::getType(void)
{
    return(type);
}

void Weapon::setType(std::string newType)
{
    type = newType;
}