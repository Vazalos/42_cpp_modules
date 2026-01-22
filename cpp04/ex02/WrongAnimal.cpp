/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:48:59 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/15 17:19:01 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal constructor called" << '\n';
}

WrongAnimal::WrongAnimal(const WrongAnimal& origAnimal) : type(origAnimal.type)
{
    std::cout << "WrongAnimal copy assignment called" << '\n';    
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& origAnimal)
{
    std::cout << "WrongAnimal copy operator called" << '\n';  
    if (this != &origAnimal)
        type = origAnimal.type;
    return(*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << '\n';  
}

void WrongAnimal::makeSound() const
{
    std::cout << "Very wrong animal sound!" << '\n';
}

std::string WrongAnimal::getType() const
{
    return(type);
}