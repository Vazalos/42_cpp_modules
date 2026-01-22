#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string newName);
    ScavTrap(const ScavTrap&);
    ScavTrap& operator=(const ScavTrap&);
    virtual ~ScavTrap();
    void attack(const std::string& target);
    void guardGate();
};

#endif