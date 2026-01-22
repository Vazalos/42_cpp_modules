/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:01:51 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/03 15:29:48 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>
#include <string>
#include <cstdlib>

class Contact
{
	public:
		Contact (void);
		Contact (int index);
		~Contact (void);
		int Contact::getIndex()
		const std::string& getFirstName();
		const std::string& getLastName();
		const std::string& getNickName();
		const std::string& getPhoneNum();
		const std::string& getDarkSecret();
		
	private:
		int	index;
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNum;
		std::string	darkSecret;
};

#endif