#ifndef BRAIN_CPP
# define BRAIN_CPP

#include <iostream>
#include <cstdlib>
#include <ctime>
	

class Brain
{
public:
    Brain();
    Brain(const Brain&);
    Brain& operator=(const Brain&);
    ~Brain();
private:
    std::string ideas[100];
};

#endif