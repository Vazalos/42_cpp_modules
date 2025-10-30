/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:30:55 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/30 15:01:43 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie* zombiePtr;
	zombiePtr = newZombie("Frank");
	zombiePtr->announce();
	delete zombiePtr;
	randomChump("Jeff");
}