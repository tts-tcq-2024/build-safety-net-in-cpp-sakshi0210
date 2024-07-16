#include <gtest/gtest.h>
#include "Soundex.h"

// Test cases for generate_soundex function

TEST(SoundexTest, EmptyString) {
    EXPECT_EQ(generate_soundex(""), "");
}

TEST(SoundexTest, SingleCharacter) {
    EXPECT_EQ(generate_soundex("A"), "A000");
}

TEST(SoundexTest, SimpleCases) {
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
