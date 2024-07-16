#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>

std::string generateSoundex(const std::string& name);
char getSoundexCode(char c);
bool isVowelOrIgnored(char c);

#endif // SOUNDEX_H

