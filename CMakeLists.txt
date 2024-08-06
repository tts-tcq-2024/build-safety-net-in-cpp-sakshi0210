cmake_minimum_required(VERSION 3.11)
project(Soundex)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include FetchContent module
include(FetchContent)

# Fetch GoogleTest
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
# FetchContent_MakeAvailable is available since CMake 3.14
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add the main executable
add_executable(SoundexTests Soundex.cpp SoundexTests.cpp)

# Link GoogleTest to the executable
target_link_libraries(SoundexTests gtest gtest_main)

# Add test
add_test(NAME SoundexTests COMMAND SoundexTests)

