#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector> 
#include <limits>

#define COLOR_BLUE_OUTPUT "\033[1;34m"
#define COLOR_GREEN_OUTPUT "\033[1;32m"
#define COLOR_RED_OUTPUT "\033[1;31m"
#define RESET_OUTPUT "\033[0m"
#define CONSOLE_FORMAT_START "\033[1;36m"
#define CONSOLE_FORMAT_END "\033[0m"

void splitFileIntoPartsOperation() {
    std::cout << COLOR_BLUE_OUTPUT << "Enter number of characters per part: " << RESET_OUTPUT;
    int partSize;
    std::cin >> partSize;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    if (partSize <= 0) { 
        std::cout << COLOR_RED_OUTPUT << "Invalid part size. Must be a positive integer." << RESET_OUTPUT << "\n";
        return; 
    }

    std::ifstream inputFile("large_file.txt");
    if (!inputFile) { 
        std::cout << COLOR_RED_OUTPUT << "Error: File large_file.txt not found." << RESET_OUTPUT << "\n";
        return; 
    }
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string content = buffer.str();
    inputFile.close();
    
    if (content.empty()) {
        std::cout << COLOR_RED_OUTPUT << "File large_file.txt is empty. No parts created." << RESET_OUTPUT << "\n";
        return;
    }

    int totalCharacters = content.length();
    int numberOfParts = (totalCharacters + partSize - 1) / partSize; 
    
    for (int i = 0; i < numberOfParts; ++i) {
        std::string partContent = content.substr(static_cast<size_t>(i) * partSize, partSize);
        std::ofstream outputFile("part" + std::to_string(i + 1) + ".txt");
        if (!outputFile) { 
            std::cout << COLOR_RED_OUTPUT << "Error creating file part" << (i + 1) << ".txt" << RESET_OUTPUT << "\n";
            continue; 
        }
        outputFile << partContent;
        outputFile.close();
    }
    std::cout << COLOR_GREEN_OUTPUT << "File large_file.txt split into " << numberOfParts << " parts." << RESET_OUTPUT << "\n";
}

int main() {
    std::cout << CONSOLE_FORMAT_START;

    std::cout << "Student: Iliia_Orlov\n";
    std::cout << "Group: M1O-101BV-24\n";
    std::cout << "Task: 2.6\n\n";
    
    splitFileIntoPartsOperation();
    
    std::cout << "\nPress Enter to exit...";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    std::cout << CONSOLE_FORMAT_END;
    return 0;
}