/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:34:44 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/05 17:09:54 by dcaetano         ###   ########.fr       */
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

typedef enum
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
	NONE
}   harlLevel;

typedef void (Harl::*HarlFn)(void);

#endif
