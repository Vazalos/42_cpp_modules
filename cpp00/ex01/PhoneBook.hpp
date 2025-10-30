/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:01:33 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/30 10:30:02 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

class PhoneBook
{
	public:
		PhoneBook (void);
		~PhoneBook (void);
		Contact	contactList[8];
		void 	addContact(void);
		void 	printContact(int index);
		void	printColumnList(void);
		void	searchContact(void);
		int		filledIndex;
	private:
		int		nextIndex;
};

#endif
