/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:11:14 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/30 15:41:08 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* zombiePtr = new Zombie[N];
	for(int i = 0; i < N; i++)
		zombiePtr[N].setName(name);
	return(zombiePtr);
}