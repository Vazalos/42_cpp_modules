/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:50:28 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/15 17:12:29 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called" << '\n';
    type = "cat";
}

Cat::Cat(const Cat& origCat): Animal(origCat)
{
    std::cout << "Cat copy assignment called" << '\n';
}

Cat& Cat::operator=(const Cat& origCat)
{
    std::cout << "Cat copy operator called" << '\n';
    if (this != &origCat)
        type = origCat.type;
    return(*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << '\n';
}

void Cat::makeSound() const
{
    std::cout << "Mi-au!" << '\n';
}