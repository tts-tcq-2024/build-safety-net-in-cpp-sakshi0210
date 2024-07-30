#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>
#include <unordered_map>

class Soundex {
public:
    std::string encode(const std::string& word) const;

private:
    char mapToDigit(char letter) const;
    std::string padToFourCharacters(const std::string& encoding) const;

    static const std::unordered_map<char, char> charToDigit;
};

#endif // SOUNDEX_H


