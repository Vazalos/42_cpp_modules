/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:01:41 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/15 17:13:25 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called" << '\n';
    type = "dog";
}

Dog::Dog(const Dog& origDog): Animal(origDog)
{
    std::cout << "Dog copy assigment called" << '\n';
}

Dog& Dog::operator=(const Dog& origDog)
{
    std::cout << "Dog copy operator called" << '\n';
    if (this != &origDog)
        type = origDog.type;
    return(*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << '\n';    
}

void Dog::makeSound() const
{
    std::cout << "W O O F" << '\n';
}