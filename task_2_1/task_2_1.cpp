#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype> 
#include <limits> 

#define COLOR_BLUE_OUTPUT "\033[1;34m"
#define COLOR_GREEN_OUTPUT "\033[1;32m"
#define COLOR_RED_OUTPUT "\033[1;31m"
#define RESET_OUTPUT "\033[0m"
#define CONSOLE_FORMAT_START "\033[1;36m"
#define CONSOLE_FORMAT_END "\033[0m"


namespace StudentFormatting {
    void startConsoleOutput() {
        std::cout << CONSOLE_FORMAT_START;
    }

    void printInfo(const std::string& taskNumber) {
        std::cout << "Student: Iliia_Orlov\n";
        std::cout << "Group: M1O-101BV-24\n";
        std::cout << "Task: " << taskNumber << "\n\n";
    }

    void endConsoleOutput() {
        std::cout << CONSOLE_FORMAT_END;
    }
}

std::string caesarCipherUtil(const std::string &text, int shift) {
    std::string result;
    for (char c : text) {
        if (std::isalpha(c)) {
            char base = std::isupper(c) ? 'A' : 'a';
            char processed_char = static_cast<char>(base + (c - base + shift % 26 + 26) % 26);
            result.push_back(processed_char);
        } else {
            result.push_back(c);
        }
    }
    return result;
}

void encryptAndDecryptFileContent() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) { 
        std::cout << COLOR_RED_OUTPUT << "File input.txt not found." << RESET_OUTPUT << "\n";
        return; 
    }
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string text = buffer.str();
    inputFile.close();
    
    int caesar_shift = 3; 
    std::string encryptedText = caesarCipherUtil(text, caesar_shift);
    std::ofstream encryptedFile("encrypted.txt");
    if (!encryptedFile) { 
        std::cout << COLOR_RED_OUTPUT << "Error opening encrypted.txt for writing." << RESET_OUTPUT << "\n";
        return; 
    }
    encryptedFile << encryptedText;
    encryptedFile.close();
    std::cout << COLOR_GREEN_OUTPUT << "File content encrypted to encrypted.txt" << RESET_OUTPUT << "\n";
    
    std::ifstream preparedEncryptedFile("encrypted.txt");
    if (!preparedEncryptedFile) { 
        std::cout << COLOR_RED_OUTPUT << "File encrypted.txt not found for decryption." << RESET_OUTPUT << "\n";
        return; 
    }
    std::stringstream encryptedBuffer;
    encryptedBuffer << preparedEncryptedFile.rdbuf();
    std::string contentToDecrypt = encryptedBuffer.str();
    preparedEncryptedFile.close();
    
    std::string decryptedText = caesarCipherUtil(contentToDecrypt, -caesar_shift);
    std::ofstream decryptedFile("decrypted.txt");
    if (!decryptedFile) { 
        std::cout << COLOR_RED_OUTPUT << "Error opening decrypted.txt for writing." << RESET_OUTPUT << "\n";
        return; 
    }
    decryptedFile << decryptedText;
    decryptedFile.close();
    std::cout << COLOR_GREEN_OUTPUT << "File content decrypted to decrypted.txt" << RESET_OUTPUT << "\n";
    std::cout << COLOR_GREEN_OUTPUT << "Encryption and decryption completed." << RESET_OUTPUT << "\n";
}

int main() {
    StudentFormatting::startConsoleOutput();
    StudentFormatting::printInfo("2.1");
    
    encryptAndDecryptFileContent();
    
    std::cout << "\nPress Enter to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    StudentFormatting::endConsoleOutput();
    return 0;
}