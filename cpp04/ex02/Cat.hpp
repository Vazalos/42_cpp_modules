#ifndef CAT_CPP
# define CAT_CPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat&);
    Cat& operator=(const Cat&);
    virtual ~Cat();
    void    makeSound() const;
private:
    Brain* brain;
};

#endif