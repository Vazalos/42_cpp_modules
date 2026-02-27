/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:08:12 by david-fe          #+#    #+#             */
/*   Updated: 2026/02/26 14:23:55 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << '\n' << "Invalid Test" << '\n';   
    try
    {
        Form Af("Aerial Traffic", 151, 50);
        Bureaucrat Ab("Ariel", 9);
        std::cout << Af << '\n';
        Ab.signForm(Af);
        std::cout << Af << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << '\n' << "Valid Test" << '\n';
    try
    { 
        Form Bf("Bombaclat", 10, 1);
        Bureaucrat Bb("Bombacrat", 3);
        std::cout << Bf << '\n';
        Bb.signForm(Bf);
        std::cout << Bf << '\n';
    }
    catch(const std::exception& f)
    {
        std::cerr << f.what() << '\n';
    }
    std::cout << "\nForm sign fail\n";
    try {
        Form form("Formy", 10, 5);
        Bureaucrat intern("Intern", 100);

        std::cout << form << '\n';
        intern.signForm(form);
        std::cout << form << '\n';
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() ;
    }

    std::cout << "\nSign same/signed form\n";
    try {
        Form document("Contract", 40, 30);
        Bureaucrat alis("Alis", 35);
        Bureaucrat bob("Bob", 50);
        Bureaucrat kirk("Kirk", 20);

        std::cout << document << '\n';

        alis.signForm(document);
        std::cout << document << '\n';
        bob.signForm(document);
        kirk.signForm(document);

        std::cout << document << '\n';
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() ;
    }
}

