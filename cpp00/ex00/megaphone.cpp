/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:52:39 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/03 15:25:30 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void useMegaphone(int ac, char **av)
{
	int i = 0;
	std::string str;

	while (++i < ac)
	{
		str = std::string(av[i]);
		for (size_t j = 0; j < str.size(); ++j) 
    		std::cout << static_cast<char>(std::toupper(str[j]));
	}
	std::cout << '\n';
}

int main(int argc, char **argv)
{
	if (argc > 1)
		useMegaphone(argc, argv);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
	return (0);
}

/*
void useMegaphoneOld(int ac, char **av)
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
		std::cout << av[i++];
	}
	std::cout << '\n';
}
*/