#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <cmath>
#include <cerrno>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
        ~ScalarConverter();
    public:
        static void convert(const std::string&);
};

#endif