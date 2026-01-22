/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:41:28 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/31 17:03:06 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB
{
private:
    std::string name;
    Weapon* weapon;
public:
    void setWeapon(Weapon& newWeapon);
    HumanB(std::string newName);
    ~HumanB(void);
    void attack();
};

#endif