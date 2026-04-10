#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
    createDB("data.csv");
}

BitcoinExchange::~BitcoinExchange()
{
    
}

static void printErr(std::string msg)
{
    std::cerr << "Error: " << msg << "\n";
}

static void printErr(std::string val, std::string msg)
{
    std::cerr << "Error: " << val << " " << msg << "\n";
}

static void printErr(float num, std::string msg)
{
    std::cerr << "Error: " << num << " " << msg << "\n";
}

static void removeSpaces(std::string& src)
{
    for(size_t it = 0; it < src.size(); it++)
    {
        if (std::isspace(src[it]))
            src.erase(it, 1);
    }
}

static float strToFloat(std::string val)
{
    std::stringstream ss(val);
    float value;
    ss >> value;
    return value;
}

static bool validDate(const std::string& date)
{
    if (date[4] != '-' || date[7] != '-')
        return false;

    //format YYYY-MM-DD
    std::stringstream yStr(date.substr(0, 4));
    std::stringstream mStr(date.substr(5, 2));
    std::stringstream dStr(date.substr(8, 2));
    unsigned int year = 0;
    unsigned int month = 0;
    unsigned int day = 0;
    yStr >> year;
    mStr >> month;
    dStr >> day;
    if (month < 1 || month > 12)
        return false;
    unsigned int maxDay = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        maxDay = 30;
    if (month == 2)
    {
        bool leapYear = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
        if (leapYear)
            maxDay = 29;
        else
            maxDay = 28;
    }
    if (day > maxDay)
        return false;
    //std::cout << year << '-' << month << '-' << day << "\n";
    return true;
}

void BitcoinExchange::createDB(const char *db)
{
    std::fstream file;
    file.open(db);

    std::string line;
    std::getline(file, line);

    while(std::getline(file, line))
    {
        size_t delimPos = line.find(',', 0);
        if ((delimPos - 1) == std::string::npos || (delimPos + 1) == std::string::npos)
        {
            continue;
        }
        
        std::string dateStr = line.substr(0, delimPos);
        std::string numStr = line.substr(delimPos + 1);

        if (validDate(dateStr))
        {
            float val = strToFloat(numStr);
            map[dateStr] = val;
        }
    }    
    // //map printer
    // std::map<std::string, float> :: iterator it;
    // for(it=map.begin();it !=map.end();++it)
    // {
    //    std::cout << it->first << " " <<it->second << "\n";
    // }
    file.close();       
}

void BitcoinExchange::parseInput(const char* input)
{
    std::fstream file;
    file.open(input);

    std::string temp;
    std::getline(file, temp);

    while(std::getline(file, temp))
    {
        size_t delimPos = temp.find('|', 0);
        if ((delimPos - 1) == std::string::npos || (delimPos + 1) == std::string::npos)
        {
            printErr("data improperly formatted or missing");
            continue;
        }

        std::string dateStr = temp.substr(0, delimPos);
        std::string numStr = temp.substr(delimPos + 1);
        removeSpaces(dateStr);
        removeSpaces(numStr);

        if (validDate(dateStr))
        {
            float val = strToFloat(numStr);
            std::map<std::string, float>::iterator it = map.lower_bound(dateStr); // or upperbound?
            if (it != map.end()) 
            {
                float price = it->second;
                float res = val * price;
                if (res < 0)
                    printErr(res, "not a positive number");
                else if (res > 1000)
                    printErr(res, "too large a number");
                else
                {
                    // SHOWCASE ALL VALS
                    //std::cout << dateStr << " (matched from " << it->first << ") => " << numStr << " (is " << val << " * " << price << ") = " << res << '\n';
                    std::cout << dateStr << " => " << numStr << " = " << res << '\n';
                }
            }
            else    
                printErr(dateStr, "could not be matched"); //ok?
        }
        else 
            printErr(dateStr, "not a valid date");
    }
    
    // //map printer
    // std::map<std::string, float> :: iterator it;
    // for(it=map.begin();it !=map.end();++it)
    // {
    //    std::cout << it->first << " " <<it->second << "\n";
    // }

    file.close();
}