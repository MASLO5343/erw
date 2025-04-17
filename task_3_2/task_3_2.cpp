#include <iostream>
#include <map>
#include <random>
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

int main() {
    std::cout
        << "\033[1;36mStudent: Iliia_Orlov\033[0m\n"
        << "\033[1;36mGroup:   M1O-101BV-24\033[0m\n"
        << "\033[1;36mTask:    3.2\033[0m\n\n";

    std::map<std::string, int> players;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 99);

    std::string name;
    while (true) {
        std::cout << "Enter player name (or 'exit' to quit): ";
        if (!std::getline(std::cin, name) || name == "exit")
            break;

        players[name] = dist(gen);
        std::cout << "\n\033[1;33mUpdated scores:\033[0m\n";
        printStdMap(players);
        std::cout << "\n";
    }

    return 0;
}
