/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:31:04 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/30 15:20:50 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);
		void announce(void);
		void setName(const std::string& newName);
	private:
		std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif