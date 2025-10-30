/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:03:23 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/30 15:45:01 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie* theHorde;
	int		zombieNum = 5;

	theHorde = zombieHorde(zombieNum, "Bob");
	/* for (int i = 0; i < zombieNum; i++)
	{
		theHorde[i].announce();
	}
	delete[] theHorde; */
}