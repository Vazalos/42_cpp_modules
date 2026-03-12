#include "Span.hpp"

Span::Span(unsigned int N) : maxN(N){}

Span::Span(const Span& origSpan)
{
    maxN = origSpan.maxN;
    nums = origSpan.nums;
}

Span& Span::operator=(const Span& origSpan)
{
    if (this != &origSpan)
    {
        maxN = origSpan.maxN;
        nums = origSpan.nums;
    }
    return(*this);
}

Span::~Span(){}

const char* Span::OverMaxSizeException::what() const throw()
{
    return("Can't add element, max number reached!");
}

const char* Span::TooFewElemsException::what() const throw()
{
    return("Too few elements to use function!");
}

void Span::addNumber(int newN)
{
    if (nums.size() < maxN)
        
        nums.push_back(newN);
    else
        throw OverMaxSizeException();
}

int Span::shortestSpan()
{
    if (nums.size() < 2)
        throw TooFewElemsException();
    std::vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    std::adjacent_difference(temp.begin(), temp.end(), temp.begin());
    return *std::min_element(temp.begin() + 1, temp.end());
}

int Span::longestSpan()
{
    if (nums.size() < 2)
        throw TooFewElemsException();
    return ( *std::max_element(nums.begin(), nums.end()) - *std::min_element(nums.begin(), nums.end()) );
}

