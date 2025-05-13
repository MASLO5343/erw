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

void mergeTwoFilesOperation() {
    std::ifstream file1("file1.txt");
    std::ifstream file2("file2.txt");

    if (!file1) { 
        std::cout << COLOR_RED_OUTPUT << "Error: file1.txt not found." << RESET_OUTPUT << "\n";
        if (file2) file2.close();
        return; 
    }
    if (!file2) {
        std::cout << COLOR_RED_OUTPUT << "Error: file2.txt not found." << RESET_OUTPUT << "\n";
        file1.close();
        return;
    }

    std::stringstream buffer;
    buffer << file1.rdbuf();
    file1.close(); 
    buffer << "\n"; 
    buffer << file2.rdbuf();
    file2.close();
    
    std::ofstream mergedFile("merged.txt");
    if (!mergedFile) { 
        std::cout << COLOR_RED_OUTPUT << "Error opening merged.txt for writing." << RESET_OUTPUT << "\n";
        return; 
    }
    mergedFile << buffer.str();
    mergedFile.close();
    std::cout << COLOR_GREEN_OUTPUT << "Files file1.txt and file2.txt merged successfully into merged.txt." << RESET_OUTPUT << "\n";
}

int main() {
    std::cout << CONSOLE_FORMAT_START;

    std::cout << "Student: Iliia_Orlov\n";
    std::cout << "Group: M1O-101BV-24\n";
    std::cout << "Task: 2.2\n\n";
    
    mergeTwoFilesOperation();
    
    std::cout << "\nPress Enter to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    std::cout << CONSOLE_FORMAT_END;
    return 0;
}