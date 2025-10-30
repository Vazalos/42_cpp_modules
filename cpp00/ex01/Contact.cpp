/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:01:07 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/30 11:54:27 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void){}

static bool hasContent(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isspace(str.c_str()[i]))
			return(true);
	}
	return(false);
}

static void contactInfoPrompt(std::string toPrint, std::string& varRef)
{
	while (true)
	{
		std::cout << "Please provide your " << toPrint << '\n';
		std::getline(std::cin, varRef);
		if (std::cin.eof())
			std::exit(1);
		if (varRef.empty() || !hasContent(varRef))
			std::cout << "Contact field cannot be empty, try again!" << '\n';
		else
			break;
	}
}

Contact::Contact(int nextIndex) 
{
	index = nextIndex;
	contactInfoPrompt("first name", firstName);
	contactInfoPrompt("last name", lastName);
	contactInfoPrompt("nickname", nickName);
	contactInfoPrompt("phone number", phoneNum);
	contactInfoPrompt("darkest secret", darkSecret);
}

Contact::~Contact(void){}