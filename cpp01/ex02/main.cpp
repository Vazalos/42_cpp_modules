/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:16:08 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/05 16:28:47 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << &string << '\n';
	std::cout << stringPTR << '\n';
	std::cout << &stringREF << '\n';
    std::cout << '\n';
	std::cout << string << '\n';
	std::cout << *stringPTR << '\n';
	std::cout << stringREF << '\n';
}
