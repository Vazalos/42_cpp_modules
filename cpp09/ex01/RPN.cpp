#include "RPN.hpp"
#include <cstring>
#include <string.h>
#include <sstream>
#include <algorithm>

RPN::RPN(){}

//RPN::RPN(int, char**){}

RPN::RPN(const RPN&){}

RPN& RPN::operator=(const RPN&)
{
    return(*this); //develop this
}

static void printErr()
{
    std::cerr << "Error" << '\n';
}

int RPN::doCalcs(char* argv)
{
    std::string args(argv);
    if (!parseArgs(args))
    {
        printErr();
        return(0);
    }
    while (!argStack.empty())
    {
        std::string token = argStack.top();
        // std::cout << token << "\n";
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (calcStack.size() <= 1)
            {
                printErr();
                return(0); 
            }
            int operand2 = calcStack.top();
            calcStack.pop();
            int operand1 = calcStack.top();
            calcStack.pop();
            
            //std::cout << operand1 << " " << token << " " << operand2 << "\n";
            if (token == "+")
                calcStack.push(operand1 + operand2);
            else if (token == "-")
                calcStack.push(operand1 - operand2);
            else if (token == "*")
                calcStack.push(operand1 * operand2);
            else if (token == "/")
                calcStack.push(operand1 / operand2);
        }
        else
        {
            calcStack.push(atoi(token.c_str()));
        }
        argStack.pop();
    }
    int res = calcStack.top();
    calcStack.pop();
    if (!calcStack.empty())
    {
        printErr();
        return(0); 
    }
    std::cout << res << "\n";
    return(1);
}

bool RPN::parseArgs(std::string& args)
{
    std::reverse(args.begin(), args.end());
    std::istringstream ss(args);
    std::string token;
    while (ss >> token)
    {
        if (!((token.length() == 1 && atoi(token.c_str())) || token == "0" || token == "+" || token == "-" || token == "*" || token == "/"))
        {
            printErr();
            return (false);
        }
        //std::cout << token << "\n";
        argStack.push(token);
    }
    return(true);
}

RPN::~RPN(){}