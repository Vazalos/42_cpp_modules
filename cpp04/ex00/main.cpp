/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:33:56 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/20 10:42:05 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const WrongAnimal* meta2 = new WrongAnimal(); 
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* k = new WrongCat();
    std::cout << '\n';
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << k->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    k->makeSound(); //will output the wronganimal sound!
    j->makeSound();
    meta->makeSound();
    meta2->makeSound();

    std::cout << '\n' << "ADDITIONAL TESTS" << '\n';
    std::cout << "[A]" << '\n';
    const Animal *A;
    A = i;
    std::cout << A->getType() << " " << std::endl;
    A->makeSound();
    std::cout << '\n';
    
    std::cout << "[B]" << '\n';
    Animal B; //this is 'slicing', uses base class makeSound()
    std::cout << B.getType() << "!" << std::endl;
    B = *j;
    std::cout << B.getType() << "!" << std::endl;
    B.makeSound();
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
    
    std::cout << "[E]" << '\n';
    WrongAnimal* E(new WrongCat);
    std::cout << E->getType() << "!" << std::endl;
    E->makeSound();
    std::cout << '\n';

    std::cout << "[F]" << '\n';
    WrongCat* F(new WrongCat);
    std::cout << F->getType() << "!" << std::endl;
    F->makeSound();
    std::cout << '\n';

    delete(meta);
    delete(meta2);
    delete(i);
    delete(j);
    delete(k);
    delete(C);
    delete(D);
    delete(E);
    delete(F);
    
    return 0;
}