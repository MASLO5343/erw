#include <iostream>
#include <map>
#include <random>
#include <string>
#include <limits>
#include <fstream>

#define CONSOLE_FORMAT_START "\033[1;36m"
#define CONSOLE_FORMAT_END "\033[0m"
#define KEY_COLOR "\033[1;34m"
#define VALUE_COLOR "\033[1;32m"
#define PROMPT_COLOR "\033[1;33m"
#define ERROR_COLOR "\033[1;31m"
#define RESET_COLOR "\033[0m"

void printPlayerScores(const std::map<std::string, int>& players) {
    if (players.empty()) {
        std::cout << "No players yet.\n";
        return;
    }
    std::cout << PROMPT_COLOR << "Current player scores:" << RESET_COLOR "\n";
    for (const auto& pair : players) {
        std::cout << KEY_COLOR << pair.first << RESET_COLOR
                  << ": "
                  << VALUE_COLOR << pair.second << RESET_COLOR
                  << "\n";
    }
}

void savePlayerScoresToFile(const std::map<std::string, int>& players, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cout << ERROR_COLOR << "Error: Could not open file " << filename << " for writing." << RESET_COLOR << "\n";
        return;
    }
    for (const auto& pair : players) {
        outFile << pair.first << ": " << pair.second << "\n";
    }
    outFile.close();
    std::cout << PROMPT_COLOR << "Player scores saved to " << filename << RESET_COLOR << "\n";
}

int main() {
    std::cout << CONSOLE_FORMAT_START;

    std::cout << "Student: Iliia_Orlov\n";
    std::cout << "Group: M1O-101BV-24\n";
    std::cout << "Task: 3.2\n\n";

    std::map<std::string, int> players;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 99);
    std::string playerName;

    while (true) {
        std::cout << PROMPT_COLOR << "Enter player name (or type 'exit' to quit, 'save' to save data): " << RESET_COLOR;
        std::getline(std::cin, playerName);

        if (playerName == "exit") {
            break;
        } else if (playerName == "save") {
            if (players.empty()) {
                std::cout << ERROR_COLOR << "No player data to save." << RESET_COLOR << "\n";
                continue;
            }
            std::cout << PROMPT_COLOR << "Enter filename to save scores: " << RESET_COLOR;
            std::string filenameToSave;
            std::getline(std::cin, filenameToSave);
            savePlayerScoresToFile(players, filenameToSave);
        } else if (!playerName.empty()) {
            players[playerName] = dist(gen);
            std::cout << "\n";
            printPlayerScores(players);
            std::cout << "\n";
        } else {
            std::cout << ERROR_COLOR << "Player name cannot be empty." << RESET_COLOR << "\n";
        }
    }
    
    std::cout << "\nFinal player scores:\n";
    printPlayerScores(players);

    std::cout << "\nPress Enter to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    std::cout << CONSOLE_FORMAT_END;
    return 0;
}