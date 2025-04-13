#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#define COLOR_BLUE "\033[1;34m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_RED "\033[1;31m"
#define RESET "\033[0m"

void searchAndReplaceInFile() {
    cout << COLOR_BLUE << "Enter word to search: " << RESET;
    string searchWord;
    cin >> searchWord;
    cout << COLOR_BLUE << "Enter word to replace: " << RESET;
    string replaceWord;
    cin >> replaceWord;
    
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
    while ((pos = content.find(searchWord, pos)) != string::npos) {
        content.replace(pos, searchWord.length(), replaceWord);
        pos += replaceWord.length();
    }
    ofstream outFile("modified.txt");
    if (!outFile) { 
        cout << COLOR_RED << "Error opening modified.txt." << RESET << "\n";
        return; 
    }
    outFile << content;
    outFile.close();
    cout << COLOR_GREEN << "Search and replace completed." << RESET << "\n";
}

int main() {
    cout << COLOR_GREEN << "Student: Iliia_Orlov" << RESET << "\n";
    cout << COLOR_GREEN << "Group: M1O-101BV-24" << RESET << "\n";
    cout << COLOR_GREEN << "Task: 2.3" << RESET << "\n\n";
    
    searchAndReplaceInFile();
    return 0;
}
