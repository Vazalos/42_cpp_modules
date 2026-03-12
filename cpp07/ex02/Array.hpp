#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>
#include <cstring>

template<typename T>
class Array
{
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& origArray);
        Array& operator=(const Array& origArray);
        ~Array();
        
        unsigned int size();
        T& operator[](const unsigned int n) const;
    private:
        unsigned int sizeN;
        T* data;
};

#include "Array.tpp"

#endif