#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string newName);
    FragTrap(const FragTrap&);
    FragTrap& operator=(const FragTrap&);
    virtual ~FragTrap();
    void highFivesGuys(void);
};

#endif