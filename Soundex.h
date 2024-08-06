#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>
#include <stdio.h>

char getSoundexCode(char c);
int updateSoundexCode(char code, int sIndex, char *soundex);
void generateSoundexCode(const char *name, char *soundex);

#endif // SOUNDEX_H

