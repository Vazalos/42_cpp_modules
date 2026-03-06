#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter&){}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
    return(*this);
}

ScalarConverter::~ScalarConverter(){}

enum type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
};

static void printChar(char c)
{
    if (isprint(c))
        std::cout << "char: " << c << '\n';
    else
        std::cout << "char: Non displayable" << '\n';
}

static void printInt(int n)
{
    std::cout << "int: " << n << '\n';
}

static void printFloat(float f)
{
    std::cout << "float: " << std::fixed << f << "f" << '\n';
}

static void printDouble(double d)
{
    std::cout << "double: " << std::fixed << d << '\n';
}

static void printImpossible(type dataType)
{
    if (dataType == CHAR)
        std::cout << "char: Impossible" << '\n';
    if (dataType == INT)
        std::cout << "int: Impossible" << '\n';
    if (dataType == FLOAT)
        std::cout << "float: Impossible" << '\n';
    if (dataType == DOUBLE)
        std::cout << "double: Impossible" << '\n';
}

static void printInvalid()
{
    printImpossible(CHAR);
    printImpossible(INT);
    printImpossible(FLOAT);
    printImpossible(DOUBLE);
}

static type typeChecker(const std::string& input)
{
    char* endChecker;

    if(input.empty())
        return(INVALID);
    if(input.size() == 1 && !isdigit(input[0]))
        return(CHAR);
    long ret = strtol(input.c_str(), &endChecker, 10);
    if(!endChecker && ret >= INT_MIN && ret <= INT_MAX)
        return(INT);
    errno = 0;
    float retF = strtof(input.c_str(), &endChecker);
    (void)retF;
    if((endChecker[0] == 'f' || endChecker[0] == 'F') &&
        endChecker[1] == '\0' && errno != ERANGE)
        return(FLOAT);
    errno = 0;
    double retD = strtod(input.c_str(), &endChecker);
    (void)retD;
    if(endChecker[0] == '\0' && errno != ERANGE)
        return(FLOAT);
    return(INVALID);
}

static void convertChar(const std::string& input)
{
    printChar(input[0]);
    printInt(static_cast<int>(input[0]));
    printFloat(static_cast<float>(input[0]));
    printDouble(static_cast<double>(input[0]));
}

static void convertInt(const std::string& input)
{
    long ret = strtol(input.c_str(), NULL, 10);
    if(ret >= CHAR_MIN && ret <= CHAR_MAX)
    {
        printChar(static_cast<char>(ret));
    }
    else 
        printImpossible(CHAR);
    printInt(ret);
    if(ret >= -FLT_MAX && ret <= FLT_MAX)
    {
        printFloat(static_cast<float>(ret));
    }
    else
        printImpossible(FLOAT);
    if(ret >= -DBL_MAX && ret <= DBL_MAX)
    {
        printDouble(static_cast<double>(ret));
    }
    else
        printImpossible(DOUBLE);
}

static void convertFloat(const std::string& input)
{
    float ret = strtof(input.c_str(), NULL);

    if (std::isnan(ret) || std::isinf(ret))
        printImpossible(CHAR);
    else if(ret >= CHAR_MIN && ret <= CHAR_MAX)
    {
        printChar(static_cast<char>(ret));
    }
    else 
        printImpossible(CHAR);

    if (std::isnan(ret) || std::isinf(ret))
        printImpossible(INT);
    else if(ret >= INT_MIN && (static_cast<int>(ret)) <= INT_MAX)
    {
        printInt(ret);
    }
    else 
        printImpossible(INT);

    printFloat(static_cast<float>(ret));
    printDouble(static_cast<double>(ret));
}

static void convertDouble(const std::string& input)
{
    double ret = strtod(input.c_str(), NULL);

    if (std::isnan(ret) || std::isinf(ret))
        printImpossible(CHAR);
    else if(ret >= CHAR_MIN && ret <= CHAR_MAX)
    {
        printChar(static_cast<char>(ret));
    }
    else 
        printImpossible(CHAR);

    if (std::isnan(ret) || std::isinf(ret))
        printImpossible(INT);
    else if(ret >= INT_MIN && ret <= INT_MAX)
    {
        printInt(ret);
    }
    else 
        printImpossible(INT);
    if(ret >= -FLT_MAX && ret <= FLT_MAX)
    {
        printFloat(static_cast<float>(ret));
    }
    printDouble(static_cast<double>(ret));
}

void ScalarConverter::convert(const std::string& input)
{
    type dataType = typeChecker(input);
    switch(dataType)
    {
        case CHAR:
        convertChar(input);
        break;

        case INT:
        convertInt(input);
        break;

        case FLOAT:
        convertFloat(input);
        break;

        case DOUBLE:
        convertDouble(input);
        break;

        default:
        printInvalid();
    }
}