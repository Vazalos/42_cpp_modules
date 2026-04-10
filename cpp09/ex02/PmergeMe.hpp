#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>

//#include list/deque

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe&);
        PmergeMe& operator=(const PmergeMe&);
        ~PmergeMe();
        void print();
        int parseArgs(int n, char **args);
        int sortVector();

    private:
        std::vector<int> vect_;
        
};

#endif