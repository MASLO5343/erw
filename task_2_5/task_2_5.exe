#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#define COLOR_BLUE "\033[1;34m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_RED "\033[1;31m"
#define RESET "\033[0m"

void searchWordInFile() {
    cout << COLOR_BLUE << "Enter word to search: " << RESET;
    string word;
    cin >> word;
    ifstream inFile("text.txt");
    if (!inFile) { 
        cout << COLOR_RED << "File text.txt not found." << RESET << "\n";
        return; 
    }
    stringstream buffer;
    buffer << inFile.rdbuf();
    string content = buffer.str();
    inFile.close();
    
    size_t pos = 0;
    int count = 0;
    while ((pos = content.find(word, pos)) != string::npos) {
        count++;
        pos += word.length();
    }
    if (count == 0)
        cout << COLOR_RED << "Word not found." << RESET << "\n";
    else
        cout << COLOR_GREEN << "Occurrences: " << count << RESET << "\n";
}

int main() {
    cout << COLOR_GREEN << "Student: Iliia_Orlov" << RESET << "\n";
    cout << COLOR_GREEN << "Group: M1O-101BV-24" << RESET << "\n";
    cout << COLOR_GREEN << "Task: 2.5" << RESET << "\n\n";
    
    searchWordInFile();
    return 0;
}
