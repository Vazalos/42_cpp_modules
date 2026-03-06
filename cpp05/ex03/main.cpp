/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:24:46 by david-fe          #+#    #+#             */
/*   Updated: 2026/03/03 16:22:18 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try 
	{
		Intern intern;
		AForm* form;
		form = intern.makeForm("presidential pardon", "Bendo");
		Bureaucrat alice("Alice", 1);
		alice.signForm(*form);
		alice.executeForm(*form);
		delete form;
	}
	catch(const std::exception& f)
    {
        std::cerr << f.what() << '\n';
    }

	std::cout << "\n";

	{
		Intern intern;
		AForm* form;
		form = intern.makeForm("robotomy request", "Bender");
		Bureaucrat alice("Alice", 1);
		alice.signForm(*form);
		alice.executeForm(*form);
		delete form;
	}

	std::cout << "\n";

	{
		Intern intern;
		AForm* form;
		form = intern.makeForm("shrubbery creation", "Benda");
		Bureaucrat alize("Alize", 1);
		alize.signForm(*form);
		alize.executeForm(*form);
		delete form;
	}

	std::cout << "\n";

	{
		Intern intern;
		AForm* form;
		form = intern.makeForm("gibberish", "Benda");
		if (form)
		{
			Bureaucrat alipe("Alipe", 1);
			alipe.signForm(*form);
			alipe.executeForm(*form);
			delete form;
		}
	}

	return 0;
}