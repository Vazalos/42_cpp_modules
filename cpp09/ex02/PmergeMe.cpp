#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe&){}

PmergeMe& PmergeMe::operator=(const PmergeMe&) //FINISH CONSTRUCTORS
{
    return(*this); //JYE
}

PmergeMe::~PmergeMe(){}

void PmergeMe::print()
{
    std::cout << "Before: " << "\n";
    std::cout << "After: " << "\n";
    std::cout << "Time to process a range of 5 elements with std::[..] : 0.00031 us" << "\n";
    std::cout << "Time to process a range of 5 elements with std::[..] : 0.00014 us" << "\n";
}

int PmergeMe::parseArgs(int n, char **args) //parse and init containers
{
    for(int i = 0; i < n; i++) //LACKING DUPLICATE CHECKS
    {
        for(int j = 0; args[i][j] != '\0'; j++)
            if(!isdigit(args[i][j]))
                return(1);
    }
    for(int i = 0; i < n; i++)
    {
        int newNum = atoi(args[i]);
        vect_.push_back(newNum);
        //other container;
    }
    // for(size_t it = 0; it < vect_.size(); it++)
    // {
    //     std::cout << "vect pos " << it << ": " << vect_[it] << "\n";
    // }
    return(0);
}

static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void printVector(std::vector<int>& vector)
{
    for(size_t i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << "\n";
    }
    std::cout << "\n";
}

static void createSequences(std::vector<int>& temp, int subsetSize, int pairMax)
{
    //
    std::cout << ":: sequence w/ " << subsetSize << " ::\n";
    std::cout << "TEMP @ size " << subsetSize << "\n";
    printVector(temp);
    //
    size_t maxPos = subsetSize * pairMax; // indices beyond are ignored for main and pend
    std::vector<int> main;
    std::vector<int> pend;

    int elemSize = (subsetSize / 2);
    for (int pair = 0; pair < pairMax; pair++) 
    {
        int startPosA = pair * subsetSize;
        // int endposA = startPosA + elemSize - 1;
        int startPosB = startPosA + elemSize;
        int endposB = startPosA + subsetSize - 1;

        for (int it = startPosA; it <= endposB; it++)
        {
            if (pair == 0 || it >= startPosB) // puts all bigger elements and first smallest into main
                main.push_back(temp[it]);
            else
                pend.push_back(temp[it]);
        }
    }
    //
    std::cout << "MAIN @ size " << subsetSize << "\n";
    printVector(main);
    std::cout << "PEND @ size " << subsetSize << "\n";
    printVector(pend);
    for (size_t it = maxPos; it < temp.size(); it++)
    {
        std::cout << "unused " << temp[it] << "\n";
    }
    //
}

static void recursiveSort(std::vector<int>& temp, int subsetSize)
{
    int tempSize = temp.size(); // numbers in container
    if (subsetSize > tempSize) // is swap operation possible?
        return;
    int pairMax = tempSize / subsetSize; // number of subsets at current size

    std::cout << "recSort w/ " << subsetSize << "\n";

    int elemSize = (subsetSize / 2);
    for (int pair = 0; pair < pairMax; pair++) 
    {
        int startPosA = pair * subsetSize;
        int endposA = startPosA + elemSize - 1;
        int startPosB = startPosA + elemSize;
        int endposB = startPosA + subsetSize - 1;

        if (temp[endposA] > temp[endposB]) // compare biggest numbers & swap
        {
            // std::cout << "swapped " << temp[endposA] << " with " << temp[endposB] << "\n"; 
            for (int it = 0; it < elemSize; it++) // swap all in range (2 x iter)
                swap(&temp[startPosA + it], &temp[startPosB + it]);
        }
    }
    // printVector(temp);
    recursiveSort(temp, 2 * subsetSize);
    createSequences(temp, subsetSize, pairMax);
}

int PmergeMe::sortVector()
{
    std::vector<int> temp = vect_;
    recursiveSort(temp, 2); // order numbers within pairs (2), pair of pairs (4), ... (8), etc.


    return (0);
}