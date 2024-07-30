#include "Soundex.h"
#include <gtest/gtest.h>

class SoundexTest : public ::testing::Test {
protected:
    Soundex soundex;
};

TEST_F(SoundexTest, EncodeSingleLetter) {
    EXPECT_EQ(soundex.encode("A"), "A000");
    EXPECT_EQ(soundex.encode("B"), "B100");
}

TEST_F(SoundexTest, EncodeSimpleWords) {
    EXPECT_EQ(soundex.encode("Robert"), "R163");
    EXPECT_EQ(soundex.encode("Rupert"), "R163");
}

TEST_F(SoundexTest, EncodeComplexWords) {
    EXPECT_EQ(soundex.encode("Jackson"), "J252");
    EXPECT_EQ(soundex.encode("Jaxson"), "J252");
}

TEST_F(SoundexTest, EncodeEmptyString) {
    EXPECT_EQ(soundex.encode(""), "0000");
}

TEST_F(SoundexTest, HandleMixedCases) {
    EXPECT_EQ(soundex.encode("RobErT"), "R163");
}

TEST_F(SoundexTest, HandleSpecialCharacters) {
    EXPECT_EQ(soundex.encode("Ro@bert"), "R163");
}

TEST_F(SoundexTest, HandleNumbers) {
    EXPECT_EQ(soundex.encode("123"), "A230");
}
