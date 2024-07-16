##include "Soundex.h"
#include <unordered_map>
#include <cctype>

// Function to get the soundex code for a given character
char get_soundex_code(char c) {
    c = std::toupper(c);
    static std::unordered_map<char, char> mapping = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'},
        {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };

    auto it = mapping.find(c);
    if (it != mapping.end()) {
        return it->second;
    }
    return '0'; // Default to '0' for non-mapped characters
}

// Function to compare characters and return the soundex code if conditions are met
std::string comparison(char ch, char prev_code) {
    if (ch != '0' && ch != prev_code) {
        return std::string(1, ch);
    } else {
        return "";
    }
}

// Function to map the rest of the name to soundex codes
std::string num_map(const std::string& name, char& prev_code) {
    std::string soundex = "";

    for (size_t i = 1; i < name.length(); ++i) {
        char ch = get_soundex_code(name[i]);
        std::string code = comparison(ch, prev_code);

        if (!code.empty()) {
            soundex += code;
            prev_code = ch;
        }
    }
    return soundex;
}

// Function to generate the soundex code for a given name
std::string generate_soundex(const std::string& name) {
    if (name.empty()) {
        return "";
    } else {
        std::string soundex(1, std::toupper(name[0]));
        char prev_code = get_soundex_code(soundex[0]);

        soundex += num_map(name, prev_code);

        if (soundex.length() > 4) {
            soundex = soundex.substr(0, 4);
        }

        // Pad with zeros if necessary
        while (soundex.length() < 4) {
            soundex += '0';
        }

        return soundex;
    }
}
