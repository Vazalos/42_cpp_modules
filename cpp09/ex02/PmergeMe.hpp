#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe&);
        PmergeMe& operator=(const PmergeMe&);
        ~PmergeMe();
        int parseArgs(int n, char **args);
        double sortVector();
        double sortDeque();
        void printResult(double vectTime, double deqTime);

    private:
        std::vector<int> unordered;
        std::vector<int> vect_;
        std::deque<int> deq_;
};

#endif