#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, HandlesSimpleCases) {
    EXPECT_EQ(generateSoundex("Robert"), "R163");
    EXPECT_EQ(generateSoundex("Rupert"), "R163");
    EXPECT_EQ(generateSoundex("Rubin"), "R150");
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
    EXPECT_EQ(generateSoundex("Ashcroft"), "A261");
    EXPECT_EQ(generateSoundex("Tymczak"), "T520");
    EXPECT_EQ(generateSoundex("Pfister"), "P236");
}

TEST(SoundexTest, HandlesNameWithDuplicates) {
    EXPECT_EQ(generateSoundex("Aardvark"), "A631");
    EXPECT_EQ(generateSoundex("Bookkeeper"), "B216");
}

TEST(SoundexTest, HandlesNameWithAllVowels) {
    EXPECT_EQ(generateSoundex("Aeiou"), "A000");
    EXPECT_EQ(generateSoundex("AeIouyHw"), "A000"); 
}

TEST(SoundexTest, HandlesNameWithMixedCases) {
    EXPECT_EQ(generateSoundex("roBErt"), "R163");
    EXPECT_EQ(generateSoundex("RuPErt"), "R163");
}

TEST(SoundexTest, HandlesNamesThatMapToSameCode) {
    EXPECT_EQ(generateSoundex("Robert"), generateSoundex("Rupert"));
    EXPECT_EQ(generateSoundex("Ashcraft"), generateSoundex("Ashcroft"));
}

TEST(SoundexTest, HandlesNameThatRequiresPadding) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("R"), "R000");
    EXPECT_EQ(generateSoundex("Ra"), "R000");
    EXPECT_EQ(generateSoundex("Ray"), "R000");
}
