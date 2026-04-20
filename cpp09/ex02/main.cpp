#include "PmergeMe.hpp"

int main(int argc, char **argv ){
    if (argc <= 1)
    {
        std::cerr << "Error" << "\n";
        return(1);
    }

    PmergeMe sorter;
    if(sorter.parseArgs(--argc, ++argv) > 0)
    {
        std::cerr << "Error" << "\n";
        return(1);
    }
    
    double vectTime = sorter.sortVector();
    double deqTime = sorter.sortDeque();
    sorter.printResult(vectTime, deqTime);

    return(0);
}