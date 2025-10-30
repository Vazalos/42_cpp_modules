/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:31:02 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/30 14:48:14 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void){};

Zombie::~Zombie(void)
{
	std::cout << Zombie::name << " the zombie has been utterly annihilated!" << '\n';
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << '\n';
}

void Zombie::setName(const std::string& newName)
{
	name = newName;
}