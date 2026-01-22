/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:31:01 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/20 11:54:26 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal constructor called" << '\n';
}

Animal::Animal(const Animal& origAnimal) : type(origAnimal.type)
{
    std::cout << "Animal copy assignment called" << '\n';
}

Animal& Animal::operator=(const Animal& origAnimal)
{
    std::cout << "Animal copy operator called" << '\n';
    if (this != &origAnimal)
        type = origAnimal.type;
    return(*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << '\n';
}

void Animal::makeSound() const
{
    std::cout << "Non-descript animal sound!" << '\n';
}

std::string Animal::getType() const
{
    return(type);
}