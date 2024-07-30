#include "gtest/gtest.h"
#include "Soundex.h"

class SoundexTests : public ::testing::Test {
protected:
    Soundex soundex;
};

TEST_F(SoundexTests, RetainsFirstLetterOfOneLetterWord) {
    EXPECT_EQ(soundex.encode("A"), "A000");
}

TEST_F(SoundexTests, PadsWithZeroesToEnsureThreeDigits) {
    EXPECT_EQ(soundex.encode("I"), "I000");
}

TEST_F(SoundexTests, ReplacesConsonantsWithAppropriateDigits) {
    EXPECT_EQ(soundex.encode("Ab"), "A100");
}

TEST_F(SoundexTests, IgnoresVowelsAndSilentLetters) {
    EXPECT_EQ(soundex.encode("Abh"), "A100");
    EXPECT_EQ(soundex.encode("Aib"), "A100");
}

TEST_F(SoundexTests, CombinesDuplicateEncodings) {
    EXPECT_EQ(soundex.encode("Abfcg"), "A120");
    EXPECT_EQ(soundex.encode("Abhbh"), "A100");
}

TEST_F(SoundexTests, LimitsLengthToFourCharacters) {
    EXPECT_EQ(soundex.encode("Abcdefghijklmnopqrstuvwxyz"), "A123");
}

TEST_F(SoundexTests, IgnoresCase) {
    EXPECT_EQ(soundex.encode("AbCdEfGh"), "A123");
}

TEST_F(SoundexTests, IgnoresNonAlphabeticCharacters) {
    EXPECT_EQ(soundex.encode("A1b2c3"), "A120");
}

