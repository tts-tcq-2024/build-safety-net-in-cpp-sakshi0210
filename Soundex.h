#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>

// Function to get the soundex code for a given character
char get_soundex_code(char c);

// Function to compare characters and return the soundex code if conditions are met
std::string comparison(char ch, char prev_code);

// Function to map the rest of the name to soundex codes
std::string num_map(const std::string& name, char& prev_code);

// Function to generate the soundex code for a given name
std::string generate_soundex(const std::string& name);

#endif // SOUNDEX_H

