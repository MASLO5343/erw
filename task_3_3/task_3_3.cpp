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

int countPlayersAboveScore(const std::map<std::string, int>& players,
                           int minScore) {
    int cnt = 0;
    for (const auto& p : players) {
        if (p.second > minScore)
            ++cnt;
    }
    return cnt;
}

int main() {
    std::cout
        << "\033[1;36mStudent: Iliia_Orlov\033[0m\n"
        << "\033[1;36mGroup:   M1O-101BV-24\033[0m\n"
        << "\033[1;36mTask:    3.3\033[0m\n\n";

    std::map<std::string, int> players;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 99);
    std::string name;

    std::cout << "\033[1;33m-- Filling players (enter 'exit' to finish) --\033[0m\n";
    while (true) {
        std::cout << "Add player name (or 'exit'): ";
        if (!std::getline(std::cin, name) || name == "exit")
            break;

        players[name] = dist(gen);
        printStdMap(players);
        std::cout << "\n";
    }

    std::cout << "\033[1;33m-- Counting (enter negative number to quit) --\033[0m\n";
    while (true) {
        std::cout << "Enter minimum score: ";
        int minScore;
        if (!(std::cin >> minScore) || minScore < 0)
            break;

        int result = countPlayersAboveScore(players, minScore);
        std::cout
            << "\033[1;35mPlayers > " << minScore << ":\033[0m "
            << result << "\n\n";

        printStdMap(players);
        std::cout << "\n";
    }

    return 0;
}
