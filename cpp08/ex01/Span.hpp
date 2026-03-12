#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>

class Span
{
    class OverMaxSizeException: public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class TooFewElemsException: public std::exception {
    public:
        virtual const char* what() const throw();
    };

    public:
        Span(unsigned int N);
        Span(const Span&);
        Span& operator=(const Span&);
        ~Span();
        int shortestSpan();
        int longestSpan();
        void addNumber(int newN);
        template<typename it>
        void addMultiNumbers(it firstN, it lastN)
        {
            for (; firstN != lastN; firstN++)
                addNumber(*firstN);
        };

    private:
        Span();
        std::vector<int> nums; 
        unsigned int maxN;
};

#endif