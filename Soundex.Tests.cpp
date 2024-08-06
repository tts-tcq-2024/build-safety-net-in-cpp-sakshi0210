#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "0000");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, BasicFunctionality) {
    EXPECT_EQ(generateSoundex("Smith"), "S530");
    EXPECT_EQ(generateSoundex("Smythe"), "S530");
}

TEST(SoundexTest, CaseInsensitivity) {
    EXPECT_EQ(generateSoundex("smith"), "S530");
    EXPECT_EQ(generateSoundex("SMITH"), "S530");
}

TEST(SoundexTest, AdjacentSimilarSoundingConsonants) {
    EXPECT_EQ(generateSoundex("Pfister"), "P123");
    EXPECT_EQ(generateSoundex("Honeyman"), "H555");
}

TEST(SoundexTest, VowelsAndIgnoredLetters) {
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
    EXPECT_EQ(generateSoundex("Tymczak"), "T522");
}

TEST(SoundexTest, EdgeCases) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex(""), "0000");
}

TEST(SoundexTest, RepeatedLettersWithHOrWInBetween) {
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
    EXPECT_EQ(generateSoundex("Tymczak"), "T522");
    EXPECT_EQ(generateSoundex("Ashworth"), "A263");
    EXPECT_EQ(generateSoundex("Jankowski"), "J520");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
