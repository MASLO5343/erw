#include <iostream>
#include <string>
using namespace std;

void startFormatting() {
    cout << "\033[1;31m";
}

void printStudentInfo() {
    cout << "Student: Iliia_Orlov\n";
    cout << "Group: М1О-101БВ-24\n";
    cout << "Task: №1\n";
}

void endFormatting() {
    cout << "\033[0m";
}

int main() {
    startFormatting();
    printStudentInfo();
    cout << "Hello, world!" << "\n";
    endFormatting();
    return 0;
}
