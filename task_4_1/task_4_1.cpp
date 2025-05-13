#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <limits>

#define RESET   "\033[0m"
#define BOLD_CYAN "\033[1;36m"
#define BOLD_YELLOW "\033[1;33m"
#define BOLD_GREEN "\033[1;32m"
#define BOLD_BLUE "\033[1;34m"
#define BOLD_MAGENTA "\033[1;35m"
#define BOLD_RED "\033[1;31m"

template <typename T>
void printVector(const std::vector<T>& vec) {
    std::cout << BOLD_MAGENTA << "My vector has " << BOLD_YELLOW << vec.size() << BOLD_MAGENTA << " of these elements:" << RESET << "\n";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << BOLD_BLUE << "[" << i << "]" << RESET << " -> " << BOLD_GREEN << vec[i] << RESET << "\n";
    }
}

template <typename T>
void printVectorToFile(const std::vector<T>& vec, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << BOLD_RED << "Error opening file: " << filename << RESET << "\n";
        return;
    }
    out << "My vector has " << vec.size() << " of these elements:\n";
    for (size_t i = 0; i < vec.size(); ++i) {
        out << "[" << i << "] -> " << vec[i] << "\n";
    }
}

template <typename T>
std::vector<T> operator+(const std::vector<T>& lhs, const std::vector<T>& rhs) {
    std::vector<T> result = lhs;
    result.insert(result.end(), rhs.begin(), rhs.end());
    std::cout << BOLD_YELLOW << "\n--- Combined Vector (Result of vec1 + vec2) ---" << RESET << std::endl;
    printVector(result);
    return result;
}

template <typename T>
std::istream& operator>>(std::istream& in, std::vector<T>& vec) {
    vec.clear();
    std::string line;
    std::getline(in, line);

    std::stringstream ss(line);
    std::string item;
    char delimiter = ' '; 

    if (line.find(',') != std::string::npos) {
        delimiter = ',';
    } else if (line.find(';') != std::string::npos) {
        delimiter = ';';
    }

    while (std::getline(ss, item, delimiter)) {
        if (item.empty()) {
            continue;
        }
        
        size_t first = item.find_first_not_of(" \t\n\r\f\v");
        if (std::string::npos == first) { 
            continue;
        }
        size_t last = item.find_last_not_of(" \t\n\r\f\v");
        std::string trimmed_item = item.substr(first, (last - first + 1));

        if (trimmed_item.empty()) {
            continue;
        }

        std::stringstream itemStream(trimmed_item);
        T value;
        if (itemStream >> value) { 
             vec.push_back(value);
        } else {
            itemStream.clear(); 
        }
    }
    return in;
}

template <typename K, typename V>
void printMap(const std::map<K, V>& m) {
    std::cout << BOLD_MAGENTA << "My map has " << BOLD_YELLOW << m.size() << BOLD_MAGENTA << " of keys and has these pairs:" << RESET << "\n";
    for (const auto& pair : m) { 
        std::cout << BOLD_BLUE << "[" << pair.first << "]" << RESET << " -> {" << BOLD_GREEN << pair.second << RESET << "}\n";
    }
}

template <typename K, typename V>
void printMapToFile(const std::map<K, V>& m, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << BOLD_RED << "Error opening file: " << filename << RESET << "\n";
        return;
    }
    out << "My map has " << m.size() << " of keys and has these pairs:\n";
    for (const auto& pair : m) {
        out << "[" << pair.first << "] -> {" << pair.second << "}\n";
    }
}

int main() {
    std::cout << BOLD_CYAN << "Student: Iliia_Orlov" << RESET << "\n"
              << BOLD_CYAN << "Group:   M1O-101BV-24" << RESET << "\n"
              << BOLD_CYAN << "Task:    4.1" << RESET << "\n\n"; 

    std::vector<int> vec1, vec2;
    std::cout << BOLD_YELLOW << "Enter elements for vector 1 (space/comma/semicolon separated):" << RESET << std::endl;
    std::cin >> vec1;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    std::cout << BOLD_YELLOW << "\nEnter elements for vector 2 (space/comma/semicolon separated):" << RESET << std::endl;
    std::cin >> vec2;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<int> combined = vec1 + vec2; 

    printVectorToFile(combined, "vector_output.txt");
    std::cout << "\n" << BOLD_GREEN << "Combined vector saved to vector_output.txt" << RESET << std::endl;

    std::cout << "\n" << BOLD_YELLOW << "--- Map Example ---" << RESET << std::endl;
    std::map<std::string, int> myMap = {
        {"apple", 5},   
        {"banana", 3},  
        {"orange", 7} 
    };
    
    printMap(myMap);
    printMapToFile(myMap, "map_output.txt");
    std::cout << BOLD_GREEN << "Map data saved to map_output.txt" << RESET << std::endl;

    return 0;
}