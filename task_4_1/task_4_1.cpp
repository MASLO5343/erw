#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <limits>
#include <algorithm> 

#define CONSOLE_FORMAT_START "\033[1;36m"
#define CONSOLE_FORMAT_END "\033[0m"

#define BOLD_CYAN_TEXT "\033[1;36m" 
#define BOLD_YELLOW_TEXT "\033[1;33m"
#define BOLD_GREEN_TEXT "\033[1;32m"
#define BOLD_BLUE_TEXT "\033[1;34m"
#define BOLD_MAGENTA_TEXT "\033[1;35m"
#define BOLD_RED_TEXT "\033[1;31m"
#define RESET_TEXT_FORMAT   "\033[0m"


template <typename T>
void printVectorCustom(const std::vector<T>& vec, std::ostream& out_stream = std::cout) {
    out_stream << BOLD_MAGENTA_TEXT << "My vector has " << BOLD_YELLOW_TEXT << vec.size() << BOLD_MAGENTA_TEXT << " of these elements:" << RESET_TEXT_FORMAT << "\n";
    for (size_t i = 0u; i < vec.size(); ++i) {
        out_stream << BOLD_BLUE_TEXT << "[" << i << "]" << RESET_TEXT_FORMAT << " -> " << BOLD_GREEN_TEXT << vec[i] << RESET_TEXT_FORMAT << "\n";
    }
}

template <typename T>
void printVectorCustomToFile(const std::vector<T>& vec, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << BOLD_RED_TEXT << "Error opening file for writing: " << filename << RESET_TEXT_FORMAT << "\n";
        return;
    }
    printVectorCustom(vec, outFile); 
    outFile.close();
    std::cout << BOLD_GREEN_TEXT << "Vector data saved to " << filename << RESET_TEXT_FORMAT << std::endl;
}

template <typename T>
std::vector<T> operator+(const std::vector<T>& lhs, const std::vector<T>& rhs) {
    std::vector<T> result = lhs;
    result.insert(result.end(), rhs.begin(), rhs.end());
    std::cout << BOLD_YELLOW_TEXT << "\n--- Combined Vector (Result of vec1 + vec2) ---" << RESET_TEXT_FORMAT << std::endl;
    printVectorCustom(result); 
    return result;
}

template <typename T>
std::istream& operator>>(std::istream& in_stream, std::vector<T>& vec) {
    vec.clear();
    std::string line;
    if (!std::getline(in_stream, line)) {
        if (in_stream.eof() && line.empty() && vec.empty()) {
            
            in_stream.clear(); 
        }
        return in_stream;
    }
    

    std::replace(line.begin(), line.end(), ',', ' ');
    std::replace(line.begin(), line.end(), ';', ' ');
    
    std::stringstream ss(line);
    T value;
    while (ss >> value) {
        vec.push_back(value);
    }

    if (ss.fail() && !ss.eof()) {
        ss.clear(); 

    }
    return in_stream;
}

template <typename K, typename V>
void printMapCustom(const std::map<K, V>& m, std::ostream& out_stream = std::cout) {
    out_stream << BOLD_MAGENTA_TEXT << "My map has " << BOLD_YELLOW_TEXT << m.size() << BOLD_MAGENTA_TEXT << " of keys and has these pairs:" << RESET_TEXT_FORMAT << "\n";
    for (const auto& pair_item : m) { 
        out_stream << BOLD_BLUE_TEXT << "[" << pair_item.first << "]" << RESET_TEXT_FORMAT << " -> {" << BOLD_GREEN_TEXT << pair_item.second << RESET_TEXT_FORMAT << "}\n";
    }
}

template <typename K, typename V>
void printMapCustomToFile(const std::map<K, V>& m, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << BOLD_RED_TEXT << "Error opening file for writing: " << filename << RESET_TEXT_FORMAT << "\n";
        return;
    }
    printMapCustom(m, outFile);
    outFile.close();
    std::cout << BOLD_GREEN_TEXT << "Map data saved to " << filename << RESET_TEXT_FORMAT << std::endl;
}

int main() {
    std::cout << CONSOLE_FORMAT_START;

    std::cout << "Student: Iliia_Orlov\n";
    std::cout << "Group: M1O-101BV-24\n";
    std::cout << "Task: 4.1\n\n";

    std::vector<int> vec1_data, vec2_data;
    std::cout << BOLD_YELLOW_TEXT << "Enter elements for vector 1 (space, comma, or semicolon separated):" << RESET_TEXT_FORMAT << std::endl;
    std::cin >> vec1_data;


    std::cout << BOLD_YELLOW_TEXT << "\nEnter elements for vector 2 (space, comma, or semicolon separated):" << RESET_TEXT_FORMAT << std::endl;
    std::cin >> vec2_data;


    std::cout << "\nVector 1 contents:" << std::endl;
    printVectorCustom(vec1_data);
    std::cout << "\nVector 2 contents:" << std::endl;
    printVectorCustom(vec2_data);

    std::vector<int> combined_vector = vec1_data + vec2_data; 
    printVectorCustomToFile(combined_vector, "vector_output.txt");

    std::cout << "\n" << BOLD_YELLOW_TEXT << "--- Map Example ---" << RESET_TEXT_FORMAT << std::endl;
    std::map<std::string, int> mySampleMap = {
        {"apple", 5},   
        {"banana", 3},  
        {"orange", 7} 
    };
    
    printMapCustom(mySampleMap);
    printMapCustomToFile(mySampleMap, "map_output.txt");

    std::cout << "\nPress Enter to exit...";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    std::cout << CONSOLE_FORMAT_END;
    return 0;
}