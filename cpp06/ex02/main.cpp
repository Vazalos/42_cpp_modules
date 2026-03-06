/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:42:53 by david-fe          #+#    #+#             */
/*   Updated: 2026/03/05 14:04:54 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    // Base * ptr1 = generate();
    // Base * ptr2 = generate();
    // Base * ptr3 = generate();

    // identify(ptr1);
    // identify(ptr2);
    // identify(ptr3);
    // identify(*ptr1);
    // identify(*ptr2);
    // identify(*ptr3);

	srand(time(NULL));

	for(int i = 0; i < 6; i++)
	{
		Base* res = generate();

		std::cout << "pointer identify -> ";
		identify(res);
		std::cout << "reference identify -> ";
		identify(*res);
		std::cout << "\n";

		delete res;
	}

	Base *a = new A();
	identify(a);
	identify(*a);
	delete a;

	Base *b = new B();
	identify(b);
	identify(*b);
	delete b;

	Base *c = new C();
	identify(c);
	identify(*c);
	delete c;

	return 0;
}