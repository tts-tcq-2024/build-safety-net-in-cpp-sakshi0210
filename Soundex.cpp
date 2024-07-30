#include "Soundex.h"
#include <cctype>
#include <unordered_map>

const std::unordered_map<char, char> Soundex::charToDigit = {
    {'b', '1'}, {'f', '1'}, {'p', '1'}, {'v', '1'},
    {'c', '2'}, {'g', '2'}, {'j', '2'}, {'k', '2'}, {'q', '2'}, {'s', '2'}, {'x', '2'}, {'z', '2'},
    {'d', '3'}, {'t', '3'},
    {'l', '4'},
    {'m', '5'}, {'n', '5'},
    {'r', '6'}
};

std::string Soundex::encode(const std::string& word) const {
    if (word.empty()) return "0000";

    std::string encoding;
    encoding += std::toupper(word[0]); // Retain the first letter

    char prevDigit = '0';
    for (size_t i = 1; i < word.size(); ++i) {
        char letter = std::tolower(word[i]);
        char digit = mapToDigit(letter);

        if (digit != prevDigit && digit != '0') {
            encoding += digit;
            prevDigit = digit;
        }
    }

    return padToFourCharacters(encoding);
}

char Soundex::mapToDigit(char letter) const {
    auto it = charToDigit.find(letter);
    return it != charToDigit.end() ? it->second : '0';
}

std::string Soundex::padToFourCharacters(const std::string& encoding) const {
    std::string result = encoding.substr(0, 1);
    for (size_t i = 1; i < encoding.size(); ++i) {
        if (result.size() < 4) {
            result += encoding[i];
        }
    }
    while (result.size() < 4) {
        result += '0';
    }
    return result;
}
