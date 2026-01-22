#ifndef DOG_CPP
# define DOG_CPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog&);
    Dog& operator=(const Dog&);
    virtual ~Dog();
    void    makeSound() const;
private:
    Brain* brain;
};

#endif