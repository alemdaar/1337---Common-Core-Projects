#include <iostream>
#include <fstream>  // Required for ifstream and ofstream
#include <string>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./copy_test <filename>" << std::endl;
        return 1;
    }

    // 1. Open the source file for reading (Input)
    std::ifstream inputFile(argv[1]);

    // 2. Check if the open was successful
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Cannot open source file." << std::endl;
        return 1;
    }

    // 3. Create/Open the destination file (Output)
    // We add ".replace" to the filename
    std::string outFileName = argv[1];
    outFileName += ".replace";
    std::ofstream outputFile(outFileName.c_str());

    if (!outputFile.is_open())
    {
        std::cerr << "Error: Cannot create output file." << std::endl;
        inputFile.close(); // Clean up
        return 1;
    }

    // 4. The Loop: Read line by line and write
    std::string line;
    while (std::getline(inputFile, line))
    {
        // In Ex04, this is where you would do the "Find and Replace" logic
        outputFile << line;
        
        // std::getline removes the newline character, so we add it back 
        // IF it's not the very last line (or just add it every time for now)
        if (!inputFile.eof())
            outputFile << std::endl;
    }

    // 5. Close the "pipes"
    inputFile.close();
    outputFile.close();

    return 0;
}
