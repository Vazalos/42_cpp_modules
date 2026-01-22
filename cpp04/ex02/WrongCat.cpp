/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:51:54 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/15 17:19:55 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat constructor called" << '\n';
    type = "wrong cat";
}

WrongCat::WrongCat(const WrongCat& origCat): WrongAnimal(origCat)
{
    std::cout << "WrongCat copy assignment called" << '\n'; 
}

WrongCat& WrongCat::operator=(const WrongCat& origCat)
{
    std::cout << "WrongCat copy operator called" << '\n'; 
    if (this != &origCat)
        type = origCat.type;
    return(*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << '\n'; 
}

void WrongCat::makeSound() const
{
    std::cout << "Hi yes I am cat. Ignore the moustache." << '\n';
}