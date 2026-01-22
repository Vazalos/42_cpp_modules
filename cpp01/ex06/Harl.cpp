/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:34:25 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/05 17:10:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){};

Harl::~Harl(){};

void Harl::complain (std::string complaint)
{
    std::string complaintLabels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    harlLevel level[5] = {DEBUG, INFO, WARNING, ERROR, NONE};
    int i;

    for (i = 0; i < 4; i++)
        if(complaint == complaintLabels[i])
            break;
    switch (level[i])
    {
    case DEBUG:
        debug();
    case INFO:
        info();
    case WARNING:
        warning();
    case ERROR:
        error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]"
            << '\n';
		break;
    }
}

void Harl::debug (void)
{
    std::cout << "[ DEBUG ]\n"
                << "I love having extra bacon for my 7XL-double-cheese-triple-"
                << "pickle-special-ketchup burger. I really do!"
                << "\n\n";
}

void Harl::info (void)
{
    std::cout << "[ INFO ]\n"
                << "I cannot believe adding extra bacon costs more money. You "
                << "didn’t put enough bacon in my burger! If you did, I "
                << "wouldn’t be asking for more!"
                << "\n\n";
}

void Harl::warning (void)
{
    std::cout << "[ WARNING ]\n"
                << "I think I deserve to have some extra bacon for free. I’ve "
                << "been coming for years, whereas you started working here "
                << "just last month."
                << "\n\n";
}

void Harl::error (void)
{
    std::cout << "[ ERROR ]\n"
                << "This is unacceptable! I want to speak to the manager now."
                << "\n\n";
}
