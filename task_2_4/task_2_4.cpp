#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#define COLOR_BLUE "\033[1;34m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_RED "\033[1;31m"
#define RESET "\033[0m"

void countCharactersInFile() {
    ifstream inFile("text.txt");
    if (!inFile) { 
        cout << COLOR_RED << "File text.txt not found." << RESET << "\n";
        return;
    }
    stringstream buffer;
    buffer << inFile.rdbuf();
    string content = buffer.str();
    inFile.close();
    cout << COLOR_GREEN << "Number of characters: " << content.size() << RESET << "\n";
}

int main() {
    cout << COLOR_GREEN << "Student: Iliia_Orlov" << RESET << "\n";
    cout << COLOR_GREEN << "Group: M1O-101BV-24" << RESET << "\n";
    cout << COLOR_GREEN << "Task: 2.4" << RESET << "\n\n";
    
    countCharactersInFile();
    return 0;
}
