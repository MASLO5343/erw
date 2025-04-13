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
    cout << "Task: №2\n";
}

string caesarEncode(const string &input, int shift) {
    string result;
    for (char c : input) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char encoded = static_cast<char>(base + (c - base + shift) % 26);
            result.push_back(encoded);
        } else {
            result.push_back(c);
        }
    }
    return result;
}

string caesarDecode(const string &input, int shift) {
    return caesarEncode(input, 26 - (shift % 26));
}

int main() {
    setConsoleFormatting();
    printStudentInfo();
    cout << "\nSelect function:\n1. Encode\n2. Decode\nYour choice: ";
    int choice;
    cin >> choice;
    cin.ignore();
    cout << "\nEnter shift (integer): ";
    int shift;
    cin >> shift;
    cin.ignore();
    cout << "\nEnter the text: ";
    string text;
    getline(cin, text);
    string result;
    if (choice == 1) {
        result = caesarEncode(text, shift);
    } else if (choice == 2) {
        result = caesarDecode(text, shift);
    } else {
        cout << "Invalid function choice.\n";
        resetConsoleFormatting();
        return 1;
    }
    cout << "\nResult: " << result << "\n";
    resetConsoleFormatting();
    return 0;
}
