#ifndef ANIMAL_CPP
# define ANIMAL_CPP

#include <iostream>

class Animal
{
public:
    Animal();
    Animal(const Animal&);
    Animal& operator=(const Animal&);
    virtual ~Animal();
    virtual void    makeSound() const;
    std::string     getType() const;
protected:
    std::string type;
};

#endif