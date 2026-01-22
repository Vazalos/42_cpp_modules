/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:34:44 by david-fe          #+#    #+#             */
/*   Updated: 2025/11/06 12:54:09 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

class Harl
{
private:
    void debug (void);
    void info (void);
    void warning (void);
    void error (void);
public:
    Harl();
    ~Harl();
    void complain (std::string level);
};

#endif