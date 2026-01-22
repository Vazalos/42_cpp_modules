/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:50:20 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/31 14:54:00 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon
{
private:
    std::string type;
public:
    const std::string& getType(void);
    void setType(std::string newType);
    Weapon();
    Weapon(std::string newType);
    ~Weapon();
};

#endif