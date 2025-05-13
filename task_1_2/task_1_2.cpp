#include <iostream>
#include <string>
#include <cctype>
#include <limits>

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

std::string caesarEncode(const std::string &input, int shift) {
    std::string result;
    for (char c : input) {
        if (std::isalpha(c)) {
            char base = std::isupper(c) ? 'A' : 'a';
            char encoded = static_cast<char>(base + (c - base + shift % 26 + 26) % 26);
            result.push_back(encoded);
        } else {
            result.push_back(c);
        }
    }
    return result;
}

std::string caesarDecode(const std::string &input, int shift) {
    return caesarEncode(input, -shift);
}

int main() {
    StudentFormatting::startConsoleOutput();
    StudentFormatting::printInfo("1.2");

    std::cout << "Caesar Cipher Program\n";
    std::cout << "Select function:\n1. Encode\n2. Decode\nYour choice: ";
    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    std::cout << "\nEnter shift (integer): ";
    int shift;
    std::cin >> shift;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    std::cout << "\nEnter the text: ";
    std::string text;
    std::getline(std::cin, text);
    std::string result_text;

    if (choice == 1) {
        result_text = caesarEncode(text, shift);
    } else if (choice == 2) {
        result_text = caesarDecode(text, shift);
    } else {
        std::cout << "Invalid function choice.\n";
        std::cout << "\nPress Enter to exit...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        StudentFormatting::endConsoleOutput();
        return 1;
    }
    std::cout << "\nResult: " << result_text << "\n";

    std::cout << "\nPress Enter to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    StudentFormatting::endConsoleOutput();
    return 0;
}