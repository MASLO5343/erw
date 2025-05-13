#include <iostream>
#include <limits>
#include <string>

namespace StudentFormatting {
    void startConsoleOutput() {
        std::cout << "\033[1;36m"; 
    }

    void printInfo(const std::string& taskNumber) {
        std::cout << "Student: Iliia_Orlov\n";
        std::cout << "Group: M1O-101BV-24\n";
        std::cout << "Task: " << taskNumber << "\n\n";
    }

    void endConsoleOutput() {
        std::cout << "\033[0m";
    }
}

int main() {
    StudentFormatting::startConsoleOutput();
    StudentFormatting::printInfo("1.1");

    std::cout << "Hello, world!" << "\n";
    
    std::cout << "\nPress Enter to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cin.get(); 

    StudentFormatting::endConsoleOutput();
    return 0;
}