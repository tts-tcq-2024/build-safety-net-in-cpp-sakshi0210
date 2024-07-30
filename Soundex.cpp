#include "Soundex.h"
#include <cctype>

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

    std::string encoding(1, std::toupper(word.front()));

    for (size_t i = 1; i < word.size(); ++i) {
        char letter = std::tolower(word[i]);
        if (charToDigit.count(letter) && (encoding.empty() || encoding.back() != charToDigit.at(letter))) {
            encoding += charToDigit.at(letter);
        }
    }

    return padToFourCharacters(encoding);
}

std::string Soundex::mapToDigit(char letter) const {
    auto it = charToDigit.find(std::tolower(letter));
    return it != charToDigit.end() ? std::string(1, it->second) : "";
}

std::string Soundex::removeDuplicateDigits(const std::string& encoding) const {
    std::string result;
    for (char digit : encoding) {
        if (result.empty() || result.back() != digit) {
            result += digit;
        }
    }
    return result;
}

std::string Soundex::padToFourCharacters(const std::string& encoding) const {
    return encoding.substr(0, 1) + removeDuplicateDigits(encoding.substr(1)).substr(0, 3) + std::string(4 - encoding.size(), '0');
}

