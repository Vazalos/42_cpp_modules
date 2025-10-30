/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:52:39 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/29 11:05:30 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void useMegaphone(int ac, char **av)
{
	int		i = { 1 };
	int		j = { 0 };
		
	while (i < ac)
	{
		while (av[i][j])
		{
			if (av[i][j] >= 'a' && av[i][j] <= 'z')
				av[i][j] -= 32;
			j++;
		}
		j = 0;
		std::cout << av[i++] << '\n';
	}
}

int main(int argc, char **argv)
{
	if (argc > 1)
		useMegaphone(argc, argv);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
	return (0);
}
