#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
    char soundex[5];
    generateSoundexCode("$rrr", soundex);
    ASSERT_STREQ(soundex, "$666");
}

TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_1) {
    char soundex[5];
    generateSoundexCode("pvt", soundex);
    ASSERT_STREQ(soundex, "P130");
}

TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_2) {
    char soundex[5];
    generateSoundexCode("*#12hi", soundex);
    ASSERT_STREQ(soundex, "*000");
}

TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_vowels) {
    char soundex[5];
    generateSoundexCode("aeiou", soundex);
    ASSERT_STREQ(soundex, "A000");
}

TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_space) {
    char soundex[5];
    generateSoundexCode(" ", soundex);
    ASSERT_STREQ(soundex, " 000");
}

TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_3) {
    char soundex[5];
    generateSoundexCode("bcdlmnr", soundex);
    ASSERT_STREQ(soundex, "B234");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
