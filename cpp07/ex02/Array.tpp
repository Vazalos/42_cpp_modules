#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array(): sizeN(0), data(NULL){}

template <typename T>
Array<T>::Array(unsigned int n) : sizeN(n)
{
    data = new T[sizeN];
}

template <typename T>
Array<T>::Array(const Array& origArray)
: sizeN(origArray.sizeN)
{
    data = new T[sizeN];
    for(unsigned int i = 0; i < sizeN; i++)
        data[i] = origArray.data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& origArray)
{
    sizeN = origArray.sizeN;
    delete[] data;
    data = new T[sizeN];
    for(unsigned int i = 0; i < sizeN; i++)
        data[i] = origArray.data[i];
    return(*this);
}

template <typename T>
Array<T>::~Array()
{
    delete[] data;
    data = NULL;
}

template <typename T>
unsigned int Array<T>::size()
{
    return(sizeN); 
}

template <typename T>
T& Array<T>::operator[](const unsigned int n) const
{
    if(n >= sizeN)
        throw std::out_of_range("index is out of range!");
    return(data[n]);
}

#endif