#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}
	
Base * generate(void)
{
    int randN = rand() % 3;

    if(randN == 0)
        return(new A());
    else if(randN == 1)
        return(new B());
    else if(randN == 2)
        return(new C());
    else
        return(NULL);
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p) != NULL)
        std::cout << "A pointer" << '\n';
    else if(dynamic_cast<B*>(p) != NULL)
        std::cout << "B pointer" << '\n';
    else if(dynamic_cast<C*>(p) != NULL)
        std::cout << "C pointer" << '\n';
    else
        std::cout << "Not A, B or C pointer!" << '\n';
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A reference" << '\n';
        return;
    }
    catch(...) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B reference" << '\n';
        return;
    }
    catch(...) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C reference" << '\n';
        return;
    }
    catch(...) {}
    std::cout << "Not A, B or C reference!" << '\n';
}
