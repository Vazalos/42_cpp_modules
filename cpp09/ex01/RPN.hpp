#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>

class RPN
{
    private:
        std::stack<int> calcStack;
        std::stack<std::string> argStack;
        RPN(const RPN&);
        RPN& operator=(const RPN&);
        bool parseArgs(std::string& args);
    public:
        RPN();
        ~RPN();
        int doCalcs(char* args);
};

#endif 