/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:34:25 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/06 10:46:16 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){};

Harl::~Harl(){};

void Harl::complain (std::string level)
{
    static const std::string complaints[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*HarlFn[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
    for (int i = 0; i < 4; i++)
    {
        if(level == complaints[i])
        {
            (this->*HarlFn[i])();
            return;
        }
    }
    std::cout << "What is this nonsense? I’m here to complain about bacon! "
                << "Stick to DEBUG, INFO, WARNING, or ERROR, or else I will "
                << "make your ass into extra bacon instead!"
                << "\n\n";
}

void Harl::debug (void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-"
                << "pickle-special-ketchup burger. I really do!"
                << "\n\n";
}

void Harl::info (void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You "
                << "didn’t put enough bacon in my burger! If you did, I "
                << "wouldn’t be asking for more!"
                << "\n\n";
}

void Harl::warning (void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve "
                << "been coming for years, whereas you started working here "
                << "just last month." 
                << "\n\n";
}

void Harl::error (void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." 
                << "\n\n";
}
