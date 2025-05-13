#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>

#define COLOR_BLUE_OUTPUT "\033[1;34m"
#define COLOR_GREEN_OUTPUT "\033[1;32m"
#define COLOR_RED_OUTPUT "\033[1;31m"
#define RESET_OUTPUT "\033[0m"
#define CONSOLE_FORMAT_START "\033[1;36m"
#define CONSOLE_FORMAT_END "\033[0m"

void searchAndReplaceInFileOperation() {
    std::cout << COLOR_BLUE_OUTPUT << "Enter word to search: " << RESET_OUTPUT;
    std::string searchWord;
    std::getline(std::cin, searchWord);

    std::cout << COLOR_BLUE_OUTPUT << "Enter word to replace with: " << RESET_OUTPUT;
    std::string replaceWord;
    std::getline(std::cin, replaceWord);
    
    std::ifstream inputFile("text.txt");
    if (!inputFile) { 
        std::cout << COLOR_RED_OUTPUT << "Error: File text.txt not found." << RESET_OUTPUT << "\n";
        return; 
    }
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string content = buffer.str();
    inputFile.close();
    
    size_t pos = 0u;
    while ((pos = content.find(searchWord, pos)) != std::string::npos) {
        content.replace(pos, searchWord.length(), replaceWord);
        pos += replaceWord.length();
    }

    std::ofstream outputFile("modified.txt");
    if (!outputFile) { 
        std::cout << COLOR_RED_OUTPUT << "Error opening modified.txt for writing." << RESET_OUTPUT << "\n";
        return; 
    }
    outputFile << content;
    outputFile.close();
    std::cout << COLOR_GREEN_OUTPUT << "Search and replace completed. Result saved to modified.txt." << RESET_OUTPUT << "\n";
}

int main() {
    std::cout << CONSOLE_FORMAT_START;

    std::cout << "Student: Iliia_Orlov\n";
    std::cout << "Group: M1O-101BV-24\n";
    std::cout << "Task: 2.3\n\n";
    
    searchAndReplaceInFileOperation();
    
    std::cout << "\nPress Enter to exit...";

    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    std::cout << CONSOLE_FORMAT_END;
    return 0;
}