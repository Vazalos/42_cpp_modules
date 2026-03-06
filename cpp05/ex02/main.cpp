/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:24:46 by david-fe          #+#    #+#             */
/*   Updated: 2026/03/03 14:06:06 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	std::cout << "ShrubberyCreationForm\n";
	try {
		ShrubberyCreationForm shrub("home");
		Bureaucrat bob("Bob", 137);

		bob.signForm(shrub);
		bob.executeForm(shrub);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	std::cout << "\nRobotomyRequestForm\n";
	try {
		RobotomyRequestForm robot("Robot");
		Bureaucrat alice("Alice", 40);

		alice.signForm(robot);
		alice.executeForm(robot);
		alice.executeForm(robot);
		alice.executeForm(robot);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	std::cout << "\nPresidentialPardonForm\n";
	try {
		PresidentialPardonForm pardon("Arthur");
		Bureaucrat dutch("Dutch", 1);

		dutch.signForm(pardon);
		dutch.executeForm(pardon);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	std::cout << "\nExecute without signing\n";
	try {
		PresidentialPardonForm pardon("Pardon");
		Bureaucrat intern("Intern", 1);

		intern.executeForm(pardon);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	std::cout << "\nInsufficient grade to execute\n";
	try {
		RobotomyRequestForm robot("Marvin");
		Bureaucrat lowLevel("LowLevel", 100);

		lowLevel.signForm(robot);
		lowLevel.executeForm(robot);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	return 0;
}