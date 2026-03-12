#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename
            MutantStack<T>::container_type::iterator iterator;
        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"

#endif