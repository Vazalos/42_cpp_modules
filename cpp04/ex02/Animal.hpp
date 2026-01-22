#ifndef ANIMAL_CPP
# define ANIMAL_CPP

#include <iostream>

class Animal
{
public:
    Animal();
    Animal(const Animal&);
    Animal& operator=(const Animal&);
    virtual ~Animal() = 0;
    virtual void    makeSound() const = 0;
    std::string     getType() const;
protected:
    std::string type;
};

#endif