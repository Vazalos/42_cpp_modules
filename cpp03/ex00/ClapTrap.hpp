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
    ~ClapTrap(void);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

private:
    std::string     name;
    int             hitPoints;
    int             energyPoints;
    int             attackDamage;
};

#endif