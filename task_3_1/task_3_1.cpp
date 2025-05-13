#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <limits> // 

#define CONSOLE_FORMAT_START "\033[1;36m"
#define CONSOLE_FORMAT_END "\033[0m"
#define KEY_COLOR "\033[1;34m"
#define VALUE_COLOR "\033[1;32m"
#define VECTOR_KEY_COLOR "\033[1;35m"
#define RESET_COLOR "\033[0m"


void printStdMap(const std::map<std::string, int>& par_map) {
    if (par_map.empty()) {
        std::cout << "Map (string, int) is empty.\n";
        return;
    }
    for (const auto& pair : par_map) {
        std::cout << KEY_COLOR << pair.first << RESET_COLOR
                  << ": "
                  << VALUE_COLOR << pair.second << RESET_COLOR
                  << "\n";
    }
}

void printVectoredMap(const std::map<std::string, std::vector<int>>& par_map) {
    if (par_map.empty()) {
        std::cout << "Map (string, vector<int>) is empty.\n";
        return;
    }
    for (const auto& pair : par_map) {
        std::cout << VECTOR_KEY_COLOR << pair.first << RESET_COLOR << ": ";
        if (pair.second.empty()) {
            std::cout << "[empty vector]";
        } else {
            for (size_t i = 0u; i < pair.second.size(); ++i) {
                std::cout << VALUE_COLOR << pair.second[i] << RESET_COLOR
                          << (i + 1u < pair.second.size() ? ", " : "");
            }
        }
        std::cout << "\n";
    }
}

int main() {
    std::cout << CONSOLE_FORMAT_START;

    std::cout << "Student: Iliia_Orlov\n";
    std::cout << "Group: M1O-101BV-24\n";
    std::cout << "Task: 3.1\n\n";

    std::cout << "Demonstrating printStdMap:\n";
    std::map<std::string, int> sampleMap1 = {{"alpha", 10}, {"beta", 20}, {"gamma", 30}};
    printStdMap(sampleMap1);
    std::cout << "\nDemonstrating printStdMap with empty map:\n";
    std::map<std::string, int> emptyMap1;
    printStdMap(emptyMap1);

    std::cout << "\nDemonstrating printVectoredMap:\n";
    std::map<std::string, std::vector<int>> sampleMap2 = {
        {"set1", {1, 2, 3}},
        {"set2", {100, 200}},
        {"set3", {}}
    };
    printVectoredMap(sampleMap2);
    std::cout << "\nDemonstrating printVectoredMap with empty map:\n";
    std::map<std::string, std::vector<int>> emptyMap2;
    printVectoredMap(emptyMap2);
    
    std::cout << "\nPress Enter to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    std::cout << CONSOLE_FORMAT_END;
    return 0;
}