/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:12:38 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/08 15:00:42 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "noSed.hpp"

void copyFile(std::ifstream& inputFile, std::ofstream& outputFile,
    std::string s1, std::string s2)
{
/*     size_t subPos;
    std::string line;
    while (true)
    {
        getline(inputFile, line);
        subPos = line.find(s1, 0);
        if (subPos != std::string::npos)
        {
            line.erase(subPos, s1.length());
            line.insert(subPos, s2);
        }
        outputFile << line << '\n';
        if (inputFile.eof())
            break;
    } */
   std::string buffer = "";
	while (!inputFile.eof())
	{
		char buf[BUFSIZ];
		std::memset(buf, 0, sizeof(buf));
		inputFile.read(buf, sizeof(buf));
		buffer += buf;
	}
	for (std::size_t i = 0; i < buffer.size(); i++)
	{
		std::size_t pos = buffer.find(s1, i);
		if (pos != std::string::npos && pos == i)
		{
			outputFile << s2;
			i += s1.size() - 1;
		}
		else
			outputFile << buffer[i];
	}
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Provide 3 args. Usage: 1 - Filename, 2 - string to replace, 3 - new string" << '\n';
        return (1);
    }
    std::string iFileName = argv[1];
    std::string oFileName = iFileName + ".replace";
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream inputFile;
    std::ofstream outputFile;

    if (!iFileName.empty())
        inputFile.open(iFileName.c_str());
    if (!inputFile.is_open())
    {
        std::cout << "Failed to open" << iFileName << '\n';
        return (2);
    }
    outputFile.open(oFileName.c_str());
    if (!outputFile.is_open())
    {
        std::cout << "Failed to create new file" << '\n';
        return (3);
    }
    copyFile(inputFile, outputFile, s1, s2);
    inputFile.close();
    outputFile.close();
    return(0);
}
