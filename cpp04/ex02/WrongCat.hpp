#ifndef WRONGCAT_CPP
# define WRONGCAT_CPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat&);
    WrongCat& operator=(const WrongCat&);
    ~WrongCat();
    void    makeSound() const;
};

#endif