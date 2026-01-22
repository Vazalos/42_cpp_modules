/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:33:56 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/20 12:01:47 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << "[A]" << '\n';
    const Animal *A;
    A = new Cat();
    std::cout << A->getType() << "!" << std::endl;
    A->makeSound();
    std::cout << '\n';

    std::cout << "[B]" << '\n';
    const Animal *B;
    B = new Dog();
    std::cout << B->getType() << "!" << std::endl;
    B->makeSound();
    std::cout << '\n';
    
    std::cout << "[C]" << '\n';
    Cat* C;
    C = new Cat();
    std::cout << C->getType() << "!" << std::endl;
    C->makeSound();
    std::cout << '\n';
    
    std::cout << "[D]" << '\n';
    Dog* D;
    D = new Dog();
    std::cout << D->getType() << "!" << std::endl;
    D->makeSound();
    std::cout << '\n';

    delete(A);
    delete(B);
    delete(C);
    delete(D);

    std::cout << "\n===============================\n\n";

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