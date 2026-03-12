#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include "easyfind.hpp"
#include <algorithm>
#include <stdexcept>
	
template <typename T>
const typename T::const_iterator easyfind(T container, int n)
{
    const typename T::const_iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::invalid_argument("Element not found in the container");
    return(it);
}

#endif