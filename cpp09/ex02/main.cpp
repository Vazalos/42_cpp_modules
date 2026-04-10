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
    sorter.sortVector();

    return(0);
}