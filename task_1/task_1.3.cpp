#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void setConsoleFormatting() {
    cout << "\033[1;36m";
}

void resetConsoleFormatting() {
    cout << "\033[0m";
}

void printStudentInfo() {
    cout << "Student: Iliia_Orlov\n";
    cout << "Group: М1О-101БВ-24\n";
    cout << "Task: №3\n";
}

string vigenereEncode(const string &input, const string &key) {
    if (input.size() != key.size()) {
        return "Error: Input and key must be of the same length.";
    }
    string result;
    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];
        char k = key[i];
        if (isalpha(c) && isalpha(k)) {
            char base = isupper(c) ? 'A' : 'a';
            char keyBase = isupper(k) ? 'A' : 'a';
            int shift = k - keyBase;
            char encoded = static_cast<char>(base + (c - base + shift) % 26);
            result.push_back(encoded);
        } else {
            result.push_back(c);
        }
    }
    return result;
}

string vigenereDecode(const string &input, const string &key) {
    if (input.size() != key.size()) {
        return "Error: Input and key must be of the same length.";
    }
    string result;
    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];
        char k = key[i];
        if (isalpha(c) && isalpha(k)) {
            char base = isupper(c) ? 'A' : 'a';
            char keyBase = isupper(k) ? 'A' : 'a';
            int shift = k - keyBase;
            char decoded = static_cast<char>(base + (c - base + 26 - shift) % 26);
            result.push_back(decoded);
        } else {
            result.push_back(c);
        }
    }
    return result;
}

int main() {
    setConsoleFormatting();
    printStudentInfo();
    cout << "\nSelect function:" << endl;
    cout << "1. Encode" << endl;
    cout << "2. Decode" << endl;
    cout << "Your choice: ";
    int choice;
    cin >> choice;
    cin.ignore();
    cout << "\nEnter the key (must be the same length as the text): ";
    string key;
    getline(cin, key);
    cout << "\nEnter the text: ";
    string text;
    getline(cin, text);
    if (key.size() != text.size()) {
        cout << "\nError: The key and text must have the same number of characters." << endl;
        resetConsoleFormatting();
        return 1;
    }
    string result;
    if (choice == 1) {
        result = vigenereEncode(text, key);
    } else if (choice == 2) {
        result = vigenereDecode(text, key);
    } else {
        cout << "\nInvalid function choice." << endl;
        resetConsoleFormatting();
        return 1;
    }
    cout << "\nResult: " << result << endl;
    resetConsoleFormatting();
    return 0;
}
