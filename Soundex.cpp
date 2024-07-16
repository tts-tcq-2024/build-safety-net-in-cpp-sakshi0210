#include "Soundex.h"
#include <cctype>
#include <unordered_map>

const std::unordered_map<char, char> soundex_mapping = {
    {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
    {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
    {'D', '3'}, {'T', '3'},
    {'L', '4'},
    {'M', '5'}, {'N', '5'},
    {'R', '6'}
};

char getSoundexCode(char c) {
    c = toupper(c);
    auto it = soundex_mapping.find(c);
    return (it != soundex_mapping.end()) ? it->second : '0';
}

bool isVowelOrIgnored(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' || c == 'h' || c == 'w';
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "0000";

    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1
