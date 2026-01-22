/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:33:56 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/20 14:39:46 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    int i;
    int petNum = 4;
    Animal* pets[petNum];
    for (i = 0; i < petNum; i++)
    {
        if(i < (petNum / 2))
            pets[i] = new Dog;
        else
            pets[i] = new Cat;
    }
    std::cout << '\n';
    for (i = 0; i < petNum; i++)
    {
        std::cout << pets[i]->getType() << '\n';
        pets[i]->makeSound();
    }
    std::cout << '\n';
    for (i = petNum - 1; i >= 0; i--)
        delete (pets[i]);
    
    return 0;
}