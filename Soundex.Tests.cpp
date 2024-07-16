#include <gtest/gtest.h>
#include "Soundex.h"

// Test cases for get_soundex_code function
TEST(SoundexTest, GetSoundexCode) {
    EXPECT_EQ(get_soundex_code('B'), '1');
    EXPECT_EQ(get_soundex_code('C'), '2');
    EXPECT_EQ(get_soundex_code('D'), '3');
    EXPECT_EQ(get_soundex_code('L'), '4');
    EXPECT_EQ(get_soundex_code('M'), '5');
    EXPECT_EQ(get_soundex_code('R'), '6');
    EXPECT_EQ(get_soundex_code('A'), '0');
}

// Test cases for comparison function
TEST(SoundexTest, Comparison) {
    EXPECT_EQ(comparison('1', '0'), "1");
    EXPECT_EQ(comparison('2', '2'), "");
    EXPECT_EQ(comparison('3', '1'), "3");
    EXPECT_EQ(comparison('0', '3'), "");
}

// Test cases for num_map function
TEST(SoundexTest, NumMap) {
    char prev_code = 'R';
    EXPECT_EQ(num_map("Rupert", prev_code), "163");
    prev_code = 'A';
    EXPECT_EQ(num_map("Ashcroft", prev_code), "261");
}

// Test cases for generate_soundex function
TEST(SoundexTest, GenerateSoundex) {
    EXPECT_EQ(generate_soundex(""), "");
    EXPECT_EQ(generate_soundex("A"), "A000");
    EXPECT_EQ(generate_soundex("Robert"), "R163");
    EXPECT_EQ(generate_soundex("Rupert"), "R163");
    EXPECT_EQ(generate_soundex("Rubin"), "R150");
    EXPECT_EQ(generate_soundex("Ashcraft"), "A261");
    EXPECT_EQ(generate_soundex("Ashcroft"), "A261");
    EXPECT_EQ(generate_soundex("Pfister"), "P236");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

