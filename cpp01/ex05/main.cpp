/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:35:42 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/06 10:46:32 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl;
    std::string complaint;
    
    if (argc == 2)
    {
        complaint = argv[1];
        harl.complain(complaint);
    }   
    else
    {
        harl.complain("DEBUG");   
        harl.complain("INFO");   
        harl.complain("WARNING");
        harl.complain("ERROR");
        harl.complain("something else");
    }
    return (0);
}