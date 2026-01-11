#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty())
    {
        std::cerr << "Error: The string to replace (s1) cannot be empty." << std::endl;
        return 1;
    }
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Cannot open source file." << std::endl;
        return 1;
    }
    std::string outFileName = filename + ".replace";
    std::ofstream outputFile(outFileName.c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Cannot create output file." << std::endl;
        inputFile.close();
        return 1;
    }
    std::string line;
    while (std::getline(inputFile, line))
    {
        size_t pos = 0;
        size_t foundPos;
        while ((foundPos = line.find(s1, pos)) != std::string::npos)
        {
            // trying to debug
            // std::cout << "number is "
            outputFile << line.substr(pos, foundPos - pos);
            outputFile << s2;
            pos = foundPos + s1.length();
        }
        outputFile << line.substr(pos);
        if (!inputFile.eof())
            outputFile << std::endl;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}