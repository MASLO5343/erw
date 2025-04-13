#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#define COLOR_BLUE "\033[1;34m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_RED "\033[1;31m"
#define RESET "\033[0m"

void splitFileIntoParts() {
    cout << COLOR_BLUE << "Enter number of characters per part: " << RESET;
    int partSize;
    cin >> partSize;
    if (partSize <= 0) { 
        cout << COLOR_RED << "Invalid value." << RESET << "\n";
        return; 
    }
    ifstream inFile("large_file.txt");
    if (!inFile) { 
        cout << COLOR_RED << "File large_file.txt not found." << RESET << "\n";
        return; 
    }
    stringstream buffer;
    buffer << inFile.rdbuf();
    string content = buffer.str();
    inFile.close();
    
    int total = content.size();
    int parts = (total + partSize - 1) / partSize;
    for (int i = 0; i < parts; i++) {
        string part = content.substr(i * partSize, partSize);
        ofstream outFile("part" + to_string(i + 1) + ".txt");
        if (!outFile) { 
            cout << COLOR_RED << "Error creating file part" << (i + 1) << ".txt" << RESET << "\n";
            continue;
        }
        outFile << part;
        outFile.close();
    }
    cout << COLOR_GREEN << "Number of parts created: " << parts << RESET << "\n";
}

int main() {
    cout << COLOR_GREEN << "Student: Iliia_Orlov" << RESET << "\n";
    cout << COLOR_GREEN << "Group: M1O-101BV-24" << RESET << "\n";
    cout << COLOR_GREEN << "Task: 2.6" << RESET << "\n\n";
    
    splitFileIntoParts();
    return 0;
}
