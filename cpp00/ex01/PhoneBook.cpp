/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:04:49 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/30 14:31:19 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	nextIndex = 0;
	filledIndex = -1;
}
PhoneBook::~PhoneBook(void){}

void PhoneBook::addContact(void)
{	
	contactList[nextIndex] = Contact(nextIndex);
	if(nextIndex < 7)
		nextIndex++;
	else
		nextIndex = 0;
	if(filledIndex < 7)
		filledIndex++;
}

std::string truncateStr(std::string& str)
{
	unsigned long	newLen = 10;
	std::string	tempStr;

	if (str.length() > newLen)
	{
		tempStr = str.substr(0, newLen - 1) + '.';
		return(tempStr);
	}
	return(str);
}

void PhoneBook::printColumnList(void)
{
	if (filledIndex >= 0)
	{
		std::cout << std::setw(10) << "index" << ' ';
		std::cout << std::setw(10) << "first name" << ' ';
		std::cout << std::setw(10) << "last name" << ' ';
		std::cout << std::setw(10) << "nickname" << '\n';
	}
	for(int i = 0; i <= filledIndex; i++)
	{
		std::cout << std::setw(10) << contactList[i].index << '|';
		std::cout << std::setw(10) << truncateStr(contactList[i].firstName) << '|';
		std::cout << std::setw(10) << truncateStr(contactList[i].lastName) << '|';
		std::cout << std::setw(10) << truncateStr(contactList[i].nickName) << '\n';
	}	
}

void PhoneBook::printContact(int index)
{	
	std::cout << contactList[index].firstName << '\n';
	std::cout << contactList[index].lastName << '\n';
	std::cout << contactList[index].nickName << '\n';
	std::cout << contactList[index].phoneNum << '\n';
	std::cout << contactList[index].darkSecret << '\n';
}

void PhoneBook::searchContact(void)
{
	std::string strIndex;
	int searchIndex;

	if (filledIndex < 0)
		std::cout << "Contact list is currently empty, try adding yours!" << '\n';
	else
	{
		while(true)
		{
			std::cout << "Provide an index to search in contacts [0 - 7]" << '\n';
			std::getline(std::cin, strIndex);
			if(std::cin.eof())
				std::exit(1);
			searchIndex = std::atoi(strIndex.c_str());
			if (searchIndex >= 0 && searchIndex <= 7)
			{
				if (searchIndex <= filledIndex)
				{
					PhoneBook::printContact(searchIndex);
					break;
				}
				else
					std::cout << "Contact index " << searchIndex <<" not yet assigned, try [0 - " 
					<< filledIndex << "]" << '\n';
			}
			else
				std::cout << "Contact index " << searchIndex << " has invalid value" << '\n';
		}
	}
}

int main(void)
{
	PhoneBook		myPhoneBook;
	std::string		command = " ";

	while (1)
	{
		std::cout << "Please introduce a command: ADD, SEARCH, EXIT" << '\n';
		std::getline(std::cin, command);
		if(std::cin.eof())
			exit(1);
		if (command.compare("ADD") == 0)
			myPhoneBook.addContact();
		if (command.compare("SEARCH") == 0)
		{
			myPhoneBook.printColumnList();
			myPhoneBook.searchContact();
		}
		if (command.compare("EXIT") == 0)
			break;
	}
	return(0);
}
