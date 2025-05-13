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

void searchWordInFileOperation() {
    std::cout << COLOR_BLUE_OUTPUT << "Enter word to search: " << RESET_OUTPUT;
    std::string wordToSearch;
    std::getline(std::cin, wordToSearch);

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
    int count = 0;
    while ((pos = content.find(wordToSearch, pos)) != std::string::npos) {
        count++;
        pos += wordToSearch.length();
    }

    if (count == 0) {
        std::cout << COLOR_RED_OUTPUT << "Word '" << wordToSearch << "' not found in text.txt." << RESET_OUTPUT << "\n";
    } else {
        std::cout << COLOR_GREEN_OUTPUT << "Word '" << wordToSearch << "' found " << count << " times in text.txt." << RESET_OUTPUT << "\n";
    }
}

int main() {
    std::cout << CONSOLE_FORMAT_START;

    std::cout << "Student: Iliia_Orlov\n";
    std::cout << "Group: M1O-101BV-24\n";
    std::cout << "Task: 2.5\n\n";
    
    searchWordInFileOperation();
    
    std::cout << "\nPress Enter to exit...";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    std::cout << CONSOLE_FORMAT_END;
    return 0;
}