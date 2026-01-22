#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
public:
    ClapTrap();
    ClapTrap(std::string newName);
    ClapTrap(const ClapTrap&);
    ClapTrap& operator=(const ClapTrap&);
    virtual ~ClapTrap(void);
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

protected:
    std::string     name;
    int             hitPoints;
    int             energyPoints;
    int             attackDamage;
};

#endif