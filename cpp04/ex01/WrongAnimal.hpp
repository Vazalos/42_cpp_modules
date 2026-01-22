#ifndef WRONGANIMAL_CPP
# define WRONGANIMAL_CPP

#include <iostream>

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal&);
    WrongAnimal& operator=(const WrongAnimal&);
    ~WrongAnimal();
    void    makeSound() const;
    std::string     getType() const;
protected:
    std::string type;
};

#endif