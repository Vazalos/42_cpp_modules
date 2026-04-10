#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <map>
#include <iostream>
#include <algorithm>

class BitcoinExchange
{
    private:
        std::map<std::string, float> map;
        void createDB(const char* db);
        BitcoinExchange(const BitcoinExchange&);
        BitcoinExchange& operator=(const BitcoinExchange&);
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        void parseInput(const char* input);
};

#endif 