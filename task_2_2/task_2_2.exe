#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#define COLOR_BLUE "\033[1;34m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_RED "\033[1;31m"
#define RESET "\033[0m"

void mergeTwoFiles() {
    ifstream file1("file1.txt"), file2("file2.txt");
    if (!file1 || !file2) { 
        cout << COLOR_RED << "One of the files file1.txt or file2.txt not found." << RESET << "\n";
        return; 
    }
    stringstream buffer;
    buffer << file1.rdbuf() << file2.rdbuf();
    file1.close();
    file2.close();
    
    ofstream merged("merged.txt");
    if (!merged) { 
        cout << COLOR_RED << "Error opening merged.txt." << RESET << "\n";
        return; 
    }
    merged << buffer.str();
    merged.close();
    cout << COLOR_GREEN << "Files merged successfully." << RESET << "\n";
}

int main() {
    cout << COLOR_GREEN << "Student: Iliia_Orlov" << RESET << "\n";
    cout << COLOR_GREEN << "Group: M1O-101BV-24" << RESET << "\n";
    cout << COLOR_GREEN << "Task: 2.2" << RESET << "\n\n";
    
    mergeTwoFiles();
    return 0;
}
