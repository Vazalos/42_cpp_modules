#ifndef ITER_HPP
# define ITER_HPP

#include <cstdio>
#include <iostream>

template <typename T>
void Iter(T* arrayPtr, const size_t n, void (*funcPtr)(T& arrayElem))
{
    for(size_t i = 0; i < n; i++)
        funcPtr(arrayPtr[i]);
}

template <typename T>
void Iter(const T* arrayPtr, const size_t n, void (*funcPtr)(const T& arrayElem))
{
    for(size_t i = 0; i < n; i++)
        funcPtr(arrayPtr[i]);
}

//Functions to call with Iter
void printStr(const std::string& str)
{
    std::cout << str << '\n';
}

template <typename T>
void printAny(const T& toPrint)
{
    std::cout << toPrint << '\n';
}

template <typename T>
void incrementN(T& n)
{
    n++;
}

template <typename T>
void incrementAny(T& Any)
{
    Any++;
}

#endif