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
#define INFO_COLOR "\033[1;35m"
#define ERROR_COLOR "\033[1;31m"
#define RESET_COLOR "\033[0m"


void printPlayerScoresDetail(const std::map<std::string, int>& players) {
    if (players.empty()) {
        std::cout << "No players in the list.\n";
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

void savePlayerScoresDetailToFile(const std::map<std::string, int>& players, const std::string& filename) {
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

int countPlayersAboveGivenScore(const std::map<std::string, int>& players, int minScore) {
    int count = 0;
    for (const auto& pair : players) {
        if (pair.second > minScore) {
            count++;
        }
    }
    return count;
}

int main() {
    std::cout << CONSOLE_FORMAT_START;

    std::cout << "Student: Iliia_Orlov\n";
    std::cout << "Group: M1O-101BV-24\n";
    std::cout << "Task: 3.3\n\n";

    std::map<std::string, int> playersList;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> scoreDist(1, 99);
    std::string playerNameInput;

    std::cout << PROMPT_COLOR << "-- Initial Player Setup --" << RESET_COLOR << "\n";
    while (true) {
        std::cout << PROMPT_COLOR << "Add player name (or type 'done' to finish setup, 'save' to save current list): " << RESET_COLOR;
        std::getline(std::cin, playerNameInput);

        if (playerNameInput == "done") {
            break;
        } else if (playerNameInput == "save") {
            if (playersList.empty()) {
                std::cout << ERROR_COLOR << "No player data to save." << RESET_COLOR << "\n";
            } else {
                std::cout << PROMPT_COLOR << "Enter filename to save scores: " << RESET_COLOR;
                std::string filenameToSave;
                std::getline(std::cin, filenameToSave);
                savePlayerScoresDetailToFile(playersList, filenameToSave);
            }
        } else if (!playerNameInput.empty()) {
            playersList[playerNameInput] = scoreDist(gen);
            printPlayerScoresDetail(playersList);
            std::cout << "\n";
        } else {
             std::cout << ERROR_COLOR << "Player name cannot be empty." << RESET_COLOR << "\n";
        }
    }

    if (playersList.empty()){
        std::cout << INFO_COLOR << "No players added. Exiting score analysis." << RESET_COLOR << "\n";
        std::cout << "\nPress Enter to exit...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        std::cout << CONSOLE_FORMAT_END;
        return 0;
    }

    std::cout << "\n" << PROMPT_COLOR << "-- Score Analysis --" << RESET_COLOR << "\n";
    while (true) {
        std::cout << PROMPT_COLOR << "Enter minimum score to count players above it (or negative number to quit, 'save' to save current list): " << RESET_COLOR;
        std::string minScoreInputStr;
        std::getline(std::cin, minScoreInputStr);

        if (minScoreInputStr == "save") {
             if (playersList.empty()) { 
                std::cout << ERROR_COLOR << "No player data to save." << RESET_COLOR << "\n";
            } else {
                std::cout << PROMPT_COLOR << "Enter filename to save scores: " << RESET_COLOR;
                std::string filenameToSave;
                std::getline(std::cin, filenameToSave);
                savePlayerScoresDetailToFile(playersList, filenameToSave);
            }
            continue;
        }
        
        int minScoreValue;
        try {
            if (minScoreInputStr.empty() || (minScoreInputStr.length() > 1 && minScoreInputStr[0] == '-' && !std::isdigit(minScoreInputStr[1])) || (minScoreInputStr.length() == 1 && minScoreInputStr[0] == '-')) {
               
            } else {
                 minScoreValue = std::stoi(minScoreInputStr);
            }
        } catch (const std::invalid_argument& ia) {

            bool potentiallyNegative = !minScoreInputStr.empty() && minScoreInputStr[0] == '-';
            if (potentiallyNegative && minScoreInputStr.length() > 1) {
                 try { minScoreValue = std::stoi(minScoreInputStr); } catch (...) { }
            } else if (potentiallyNegative && minScoreInputStr.length() == 1) { 
                 std::cout << ERROR_COLOR << "Invalid input. Please enter a number, 'save', or a negative number to quit." << RESET_COLOR << "\n"; continue;
            }
            else { 
                 std::cout << ERROR_COLOR << "Invalid input. Please enter a number, 'save', or a negative number to quit." << RESET_COLOR << "\n"; continue;
            }
        } catch (const std::out_of_range& oor) {
            std::cout << ERROR_COLOR << "Input out of range for an integer." << RESET_COLOR << "\n";
            continue;
        }


        if (minScoreValue < 0) {
            break;
        }

        int playersAbove = countPlayersAboveGivenScore(playersList, minScoreValue);
        std::cout << INFO_COLOR << "Number of players with score > " << minScoreValue << ": " << playersAbove << RESET_COLOR << "\n\n";
        printPlayerScoresDetail(playersList); 
        std::cout << "\n";
    }
    
    std::cout << "\nPress Enter to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    std::cout << CONSOLE_FORMAT_END;
    return 0;
}