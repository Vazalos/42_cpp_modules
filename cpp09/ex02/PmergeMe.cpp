#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& other) : unordered(other.unordered), vect_(other.vect_), deq_(other.deq_){}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (&other != this)
    {
        unordered = other.unordered;
        vect_ = other.vect_;
        deq_ = other.deq_;
    }
    return(*this);
}

PmergeMe::~PmergeMe(){}

int PmergeMe::parseArgs(int n, char **args) //parse and init containers
{
    for(int i = 0; i < n; i++) // is fully numeric?
    {
        for(int j = 0; args[i][j] != '\0'; j++)
            if(!isdigit(args[i][j]))
                return(1);
    }
    for(int i = 0; i < (n - 1); i++) // has duplicates?
    {
        for(int j = i + 1; j < n; j++)
        {
            if(strcmp(args[i], args[j]) == 0)
                return(2);
        }
    }
    for(int i = 0; i < n; i++) // fill containers
    {
        int newNum = atoi(args[i]);
        vect_.push_back(newNum);
        deq_.push_back(newNum);
    }
    unordered = vect_;
    return(0);
}

static double startTime() {
    timeval startTv;
    gettimeofday(&startTv, 0);
    return startTv.tv_sec * 1e6 + startTv.tv_usec;
}

static double elapsedTime(double startTime) {
    timeval endTv;
    gettimeofday(&endTv, 0);
    double endTime = endTv.tv_sec * 1e6 + endTv.tv_usec;
    return (endTime - startTime);
}

static void printVector(const std::vector<int>& vector)
{
    for(size_t i = 0; i < vector.size(); i++)
    {
        if (i)
            std::cout << " ";
        std::cout << vector[i];
    }
    std::cout << "\n";
}

static void printDeque(const std::deque<int>& deque)
{
    for(size_t i = 0; i < deque.size(); i++)
    {
        if (i)
            std::cout << " ";
        std::cout << deque[i];
    }
    std::cout << "\n";
}

void PmergeMe::printResult(double vectTime, double deqTime)
{
    std::cout << "Before: " << "\n";
    printVector(unordered);
    std::cout << "After (vector): " << "\n";
    printVector(vect_);    
    std::cout << "After (deque): " << "\n";
    printDeque(deq_); 
    std::cout << "Time to process a range of " << vect_.size() << " elements with std::vector : " << vectTime << " us\n";
    std::cout << "Time to process a range of " << deq_.size() << " elements with std::deque : " << deqTime << " us\n";
}

// ### VECTOR Section of the algo ###

static size_t binarySearch(size_t lowPos, size_t highPos, std::vector<int>& vector, int toInsert)
{
    while (lowPos < highPos)
    {
        size_t comparePos = lowPos + (highPos - lowPos) / 2;
        if (vector[comparePos] > toInsert)  // search range becomes lower half
            highPos = comparePos;           // non-inclusive upper bound
        else                                // search range becomes higher half
            lowPos = comparePos + 1;
    }
    return(lowPos);
}

static size_t findBiggerPos(std::vector<int>& ret, const std::vector<std::pair<int, int> > pairs, int currSmall)
{
    int biggerPos = ret.size() - 1;
    int pairedNum = 0;
    bool hasPair = false;

    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (currSmall == pairs[i].first)
        {
            hasPair = true;
            pairedNum = pairs[i].second; 
        }
    }
    if (!hasPair) // return default for unpaired odd one out -> search entire container
        return(biggerPos);
    for (size_t i = 0; i < ret.size(); i++)
    {
        if (pairedNum == ret[i])
            biggerPos = i;
    }
    return(biggerPos);
}

static std::vector<int> insertRemaining(const std::vector<int>& biggers, std::vector<int>& smalls, const std::vector<std::pair<int, int> > pairs)
{
    std::vector<int> ret = biggers;
    size_t idxMinus1 = 1; // Jacosthal elem n-1
    size_t idxMinus2 = 0; // Jacosthal elem n-2
    size_t prevInsertedAt = 0; // tracks previously inserted max indices (== idxMinus except for 1st loop)
    size_t idxCap = 0; // current max index to decrement from (1, 3 -> 2, 5 -> 4, 11 -> 6, etc.)
    size_t smallsLen =  smalls.size();
    bool loopFlag = true;

    for(size_t it = 0; it < pairs.size(); it++) // swap smalls[0] w/ the pair of the smallest bigger and inserts it
    {
        if (biggers[0] == pairs[it].second)
            std::swap(smalls[it], smalls[0]);
    }
    ret.insert(ret.begin(), smalls[0]);

    while (loopFlag)
    {
        idxCap = idxMinus1 + (idxMinus2 * 2); // Jacobsthal formula for next number
        if (idxCap >= smallsLen) // is greater than last possible index?
        {
            idxCap = smallsLen - 1;
            loopFlag = false; // end after current set of indices
        }

        for (size_t currIdx = idxCap; currIdx > prevInsertedAt; currIdx--) // inserts in range [prev searched indices - next Jacobsthal number]
        {
            int toInsert = smalls[currIdx];
            size_t upperBound = findBiggerPos(ret, pairs, toInsert);
            size_t insertionPos = binarySearch(0, upperBound + 1, ret, toInsert); // need special condition to insert straggler
            ret.insert(ret.begin() + insertionPos, toInsert);
        }
        idxMinus2 = idxMinus1;
        idxMinus1 = idxCap;
        prevInsertedAt = idxMinus1;
    }
    // std::cout << "printing biggers, size: " << biggers.size() << "\n";
    // printVector(biggers);
    // std::cout << "printing smalls, size: " << smalls.size() << "\n";
    // printVector(smalls);
    // std::cout << "printing ret, size: " << ret.size() << "\n";
    // printVector(ret);
    return(ret);
}

static std::vector<int> recursiveSort(const std::vector<int>& temp)
{
    int tempSize = temp.size();
    if (tempSize <= 1)
        return(temp);

    std::vector<int> biggers;
    std::vector<int> smalls;
    std::vector<std::pair<int, int> > pairs;

    int pairMax = tempSize / 2; // number of subsets at current size
    bool straggler = tempSize % 2; // odd one out
    // std::cout << "recSort w/ " << pairMax << " pairs, and " << straggler << " struggler\n";
    for (int pair = 0; pair < pairMax; pair++) 
    {
        int aPos = pair * 2;
        int bPos = aPos + 1;
        int min = std::min(temp[aPos], temp[bPos]);
        int max = std::max(temp[aPos], temp[bPos]);

        biggers.push_back(max);
        smalls.push_back(min);
        pairs.push_back(std::pair<int, int>(min, max)); // keep pair info
    }
    if (straggler) // odd one out inserted in smalls
        smalls.push_back(temp[tempSize - 1]);
    // printVector(biggers);
    // printVector(smalls);
    // printPairs(pairs);
    biggers = recursiveSort(biggers); // have to send biggers, and it has (size/2) each call 
    std::vector<int> sorted = insertRemaining(biggers, smalls, pairs); // inserts the smaller paired elements + straggler, if it exists
    return(sorted);
}

// static void isSorted(const std::vector<int>& vector)
// {
//     for (size_t it = 0; it < (vector.size() - 1); it++)
//         if(vector[it] > vector[it + 1])
//             std::cout << "NOT SORTED\n";
//     std::cout << "DONE\n";
// }


// static void printPairs(const std::vector<std::pair<int, int> >& pairs)
// {
//     for(size_t i = 0; i < pairs.size(); i++)
//     {
//         std::cout << "pair n" << i << ": " << pairs[i].first << ", " << pairs[i].second << "\n";
//     }
//     std::cout << "\n";
// }

double PmergeMe::sortVector()
{
    double start = startTime();
    std::vector<int> temp = vect_;
    vect_ = recursiveSort(temp);
    double elapsed = elapsedTime(start);

    // printVector(temp);
    // isSorted(temp);

    return (elapsed);
}




// ### DEQUE Section of the algo ###

static size_t binarySearch(size_t lowPos, size_t highPos, std::deque<int>& deque, int toInsert)
{
    while (lowPos < highPos)
    {
        size_t comparePos = lowPos + (highPos - lowPos) / 2;
        if (deque[comparePos] > toInsert)  // search range becomes lower half
            highPos = comparePos;           // non-inclusive upper bound
        else                                // search range becomes higher half
            lowPos = comparePos + 1;
    }
    return(lowPos);
}

static size_t findBiggerPos(std::deque<int>& ret, const std::deque<std::pair<int, int> > pairs, int currSmall)
{
    int biggerPos = ret.size() - 1;
    int pairedNum = 0;
    bool hasPair = false;

    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (currSmall == pairs[i].first)
        {
            hasPair = true;
            pairedNum = pairs[i].second; 
        }
    }
    if (!hasPair) // return default for unpaired odd one out -> search entire container
        return(biggerPos);
    for (size_t i = 0; i < ret.size(); i++)
    {
        if (pairedNum == ret[i])
            biggerPos = i;
    }
    return(biggerPos);
}

static std::deque<int> insertRemaining(const std::deque<int>& biggers, std::deque<int>& smalls, const std::deque<std::pair<int, int> > pairs)
{
    std::deque<int> ret = biggers;
    size_t idxMinus1 = 1; // Jacosthal elem n-1
    size_t idxMinus2 = 0; // Jacosthal elem n-2
    size_t prevInsertedAt = 0; // tracks previously inserted max indices (== idxMinus except for 1st loop)
    size_t idxCap = 0; // current max index to decrement from (1, 3 -> 2, 5 -> 4, 11 -> 6, etc.)
    size_t smallsLen =  smalls.size();
    bool loopFlag = true;

    for(size_t it = 0; it < pairs.size(); it++) // swap smalls[0] w/ the pair of the smallest bigger and inserts it
    {
        if (biggers[0] == pairs[it].second)
            std::swap(smalls[it], smalls[0]);
    }
    ret.insert(ret.begin(), smalls[0]);

    while (loopFlag)
    {
        idxCap = idxMinus1 + (idxMinus2 * 2); // Jacobsthal formula for next number
        if (idxCap >= smallsLen) // is greater than last possible index?
        {
            idxCap = smallsLen - 1;
            loopFlag = false; // end after current set of indices
        }

        for (size_t currIdx = idxCap; currIdx > prevInsertedAt; currIdx--) // inserts in range [prev searched indices - next Jacobsthal number]
        {
            int toInsert = smalls[currIdx];
            size_t upperBound = findBiggerPos(ret, pairs, toInsert);
            size_t insertionPos = binarySearch(0, upperBound + 1, ret, toInsert); // need special condition to insert straggler
            ret.insert(ret.begin() + insertionPos, toInsert);
        }
        idxMinus2 = idxMinus1;
        idxMinus1 = idxCap;
        prevInsertedAt = idxMinus1;
    }
    // std::cout << "printing biggers, size: " << biggers.size() << "\n";
    // printDeque(biggers);
    // std::cout << "printing smalls, size: " << smalls.size() << "\n";
    // printDeque(smalls);
    // std::cout << "printing ret, size: " << ret.size() << "\n";
    // printDeque(ret);
    return(ret);
}

static std::deque<int> recursiveSort(const std::deque<int>& temp)
{
    int tempSize = temp.size();
    if (tempSize <= 1)
        return(temp);

    std::deque<int> biggers;
    std::deque<int> smalls;
    std::deque<std::pair<int, int> > pairs;

    int pairMax = tempSize / 2; // number of subsets at current size
    bool straggler = tempSize % 2; // odd one out
    // std::cout << "recSort w/ " << pairMax << " pairs, and " << straggler << " struggler\n";
    for (int pair = 0; pair < pairMax; pair++) 
    {
        int aPos = pair * 2;
        int bPos = aPos + 1;
        int min = std::min(temp[aPos], temp[bPos]);
        int max = std::max(temp[aPos], temp[bPos]);

        biggers.push_back(max);
        smalls.push_back(min);
        pairs.push_back(std::pair<int, int>(min, max)); // keep pair info
    }
    if (straggler) // odd one out inserted in smalls
        smalls.push_back(temp[tempSize - 1]);
    // printDeque(biggers);
    // printDeque(smalls);
    // printPairs(pairs);
    biggers = recursiveSort(biggers); // have to send biggers, and it has (size/2) each call 
    std::deque<int> sorted = insertRemaining(biggers, smalls, pairs); // inserts the smaller paired elements + straggler, if it exists
    return(sorted);
}

// static void isSorted(const std::deque<int>& deque)
// {
//     for (size_t it = 0; it < (deque.size() - 1); it++)
//         if(deque[it] > deque[it + 1])
//             std::cout << "NOT SORTED\n";
//     std::cout << "DONE\n";
// }


// static void printPairs(const std::deque<std::pair<int, int> >& pairs)
// {
//     for(size_t i = 0; i < pairs.size(); i++)
//     {
//         std::cout << "pair n" << i << ": " << pairs[i].first << ", " << pairs[i].second << "\n";
//     }
//     std::cout << "\n";
// }

double PmergeMe::sortDeque()
{
    double start = startTime();
    std::deque<int> temp = deq_;
    deq_ = recursiveSort(temp);
    double elapsed = elapsedTime(start);

    // printDeque(temp);
    // isSorted(temp);

    return (elapsed);
}