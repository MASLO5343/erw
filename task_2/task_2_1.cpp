#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// ANSI escape codes for color formatting
#define COLOR_BLUE "\033[1;34m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_RED "\033[1;31m"
#define RESET "\033[0m"

// Caesar cipher function
string caesarCipher(const string &text, int shift) {
    string result;
    for (char c : text) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            char base = (c >= 'A' && c <= 'Z') ? 'A' : 'a';
            int offset = (c - base + shift) % 26; // 26 is int literal
            if (offset < 0)
                offset += 26;
            result.push_back(base + offset);
        } else {
            result.push_back(c);
        }
    }
    return result;
}

void encryptAndDecryptFile() {
    ifstream input("input.txt");
    if (!input) { 
        cout << COLOR_RED << "File input.txt not found." << RESET << "\n";
        return; 
    }
    stringstream buffer;
    buffer << input.rdbuf();
    string text = buffer.str();
    input.close();
    
    int shift = 3; // int literal: 3
    string encryptedText = caesarCipher(text, shift);
    ofstream outEnc("encrypted.txt");
    if (!outEnc) { 
        cout << COLOR_RED << "Error opening encrypted.txt." << RESET << "\n";
        return; 
    }
    outEnc << encryptedText;
    outEnc.close();
    
    ifstream encIn("encrypted.txt");
    if (!encIn) { 
        cout << COLOR_RED << "File encrypted.txt not found." << RESET << "\n";
        return; 
    }
    stringstream encBuffer;
    encBuffer << encIn.rdbuf();
    string encContent = encBuffer.str();
    encIn.close();
    
    string decryptedText = caesarCipher(encContent, -shift);
    ofstream outDec("decrypted.txt");
    if (!outDec) { 
        cout << COLOR_RED << "Error opening decrypted.txt." << RESET << "\n";
        return; 
    }
    outDec << decryptedText;
    outDec.close();
    cout << COLOR_GREEN << "Encryption and decryption completed." << RESET << "\n";
}

int main() {
    // Header output with required formatting
    cout << COLOR_GREEN << "Student: Iliia_Orlov" << RESET << "\n";
    cout << COLOR_GREEN << "Group: M1O-101BV-24" << RESET << "\n";
    cout << COLOR_GREEN << "Task: 2.1" << RESET << "\n\n";
    
    encryptAndDecryptFile();
    return 0;
}
