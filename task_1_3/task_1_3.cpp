#include <iostream>
#include <string>
#include <cctype>
#include <vector>
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

std::string vigenereProcess(const std::string &input, const std::string &key, bool encode) {
    std::string result = "";
    if (key.empty()) return "Error: Key cannot be empty.";
    for (size_t i = 0u; i < input.length(); ++i) {
        char p_char = input[i];
        char k_char = key[i % key.length()];

        if (std::isalpha(p_char)) {
            char base = std::isupper(p_char) ? 'A' : 'a';
            int key_shift = std::toupper(k_char) - 'A';
            if (!encode) {
                key_shift = -key_shift;
            }
            char processed_char = static_cast<char>(base + (p_char - base + key_shift % 26 + 26) % 26);
            result += processed_char;
        } else {
            result += p_char;
        }
    }
    return result;
}

std::string vigenereEncode(const std::string &input, const std::string &key) {
    if (input.size() != key.size()) {
         return "Error: Input and key must be of the same length for this specific version.";
    }
    return vigenereProcess(input, key, true);
}

std::string vigenereDecode(const std::string &input, const std::string &key) {
     if (input.size() != key.size()) {
         return "Error: Input and key must be of the same length for this specific version.";
    }
    return vigenereProcess(input, key, false);
}

int main() {
    StudentFormatting::startConsoleOutput();
    StudentFormatting::printInfo("1.3");
    
    std::cout << "Vigenere Cipher Program\n";
    std::cout << "Select function:\n1. Encode\n2. Decode\nYour choice: ";
    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    std::cout << "\nEnter the key: ";
    std::string key;
    std::getline(std::cin, key);

    std::cout << "\nEnter the text (must be same length as key for this version): ";
    std::string text;
    std::getline(std::cin, text);
    std::string result_text;

    if (key.size() != text.size()) {
        std::cout << "\nError: The key and text must have the same number of characters for this specific version." << std::endl;
        std::cout << "\nPress Enter to exit...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        StudentFormatting::endConsoleOutput();
        return 1;
    }

    if (choice == 1) {
        result_text = vigenereEncode(text, key);
    } else if (choice == 2) {
        result_text = vigenereDecode(text, key);
    } else {
        std::cout << "Invalid function choice.\n";
        std::cout << "\nPress Enter to exit...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        StudentFormatting::endConsoleOutput();
        return 1;
    }
    std::cout << "\nResult: " << result_text << std::endl;

    std::cout << "\nPress Enter to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    StudentFormatting::endConsoleOutput();
    return 0;
}