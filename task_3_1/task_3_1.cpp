#include <iostream>
#include <map>
#include <vector>
#include <string>


void printStdMap(const std::map<std::string, int>& par_map) {
    for (const auto& p : par_map) {
        std::cout
            << "\033[1;34m" << p.first << "\033[0m"
            << ": "
            << "\033[1;32m" << p.second << "\033[0m"
            << "\n";
    }
}


void printVectoredMap(const std::map<std::string, std::vector<int>>& par_map) {
    for (const auto& p : par_map) {
        std::cout
            << "\033[1;35m" << p.first << "\033[0m"
            << ": ";
        for (size_t i = 0; i < p.second.size(); ++i) {
            std::cout << p.second[i]
                      << (i + 1 < p.second.size() ? ", " : "");
        }
        std::cout << "\n";
    }
}

int main() {
    std::cout
        << "\033[1;36mStudent: Iliia_Orlov\033[0m\n"
        << "\033[1;36mGroup:   M1O-101BV-24\033[0m\n"
        << "\033[1;36mTask:    3.1\033[0m\n";
    return 0;
}
