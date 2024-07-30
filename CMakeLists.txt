cmake_minimum_required(VERSION 3.10)
project(SoundexTest)

set(CMAKE_CXX_STANDARD 17)

# Add the executable
add_executable(testchecker Soundex.cpp SoundexTests.cpp)

# Add Google Test
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Link Google Test to the executable
target_link_libraries(testchecker gtest_main)

enable_testing()

add_test(NAME SoundexTest COMMAND testchecker)
