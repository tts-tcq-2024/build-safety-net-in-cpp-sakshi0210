#include "Soundex.h"
#include <cctype>
#include <unordered_map>

char getSoundexCode(char c) {
    switch (toupper(c)) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0'; // For A, E, I, O, U, H, W, Y
    }
}

std::string removeDuplicates(const std::string& name) {
    std::string result(1, name[0]);
    for (size_t i = 1; i < name.size(); ++i) {
        if (getSoundexCode(name[i]) != getSoundexCode(name[i - 1]) || getSoundexCode(name[i]) == '0') {
            result += name[i];
        }
    }
    return result;
}

std::string applySoundexRules(const std::string& name) {
    std::string result(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.size() && result.size() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            result += code;
            prevCode = code;
        }
    }

    while (result.size() < 4) {
        result += '0';
    }

    return result;
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "0000";

    std::string processedName = removeDuplicates(name);
    return applySoundexRules(processedName);
}
