#include "Soundex.h"

char getSoundexCode(char c) {
    static const char codeTable[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };
    c = toupper(c);
    if (isalpha(c)) {
        return codeTable[c - 'A'];
    }
    return '0';
}

int updateSoundexCode(char code, int sIndex, char *soundex) {
    if (code != '0') {
        soundex[sIndex] = code;
        return ++sIndex;
    }
    return sIndex;
}

void generateSoundexCode(const char *name, char *soundex) {
    soundex[0] = toupper(name[0]);
    int sIndex = 1;
    for (int i = 1; name[i] != '\0' && sIndex <= 3; i++) {
        char code = getSoundexCode(name[i]);
        sIndex = updateSoundexCode(code, sIndex, soundex);
    }
    memset(soundex + sIndex, '0', 4 - sIndex);
    soundex[4] = '\0';
}
