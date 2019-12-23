cmake_minimum_required (VERSION 2.8.12.2) # If your CMake version is older, try modifying this line
project(SuffixTree)

add_definitions(-std=c++1z -g)

########## Create libraries
add_library(suffixTreeLib suffixTree.cpp)
add_library(linearizationLib linearization.cpp suffixTree.cpp)
add_library(suffixArrayLib suffixArray.cpp suffixTree.cpp)

########## Link GoogleTest
include_directories($ENV{GMOCK_HOME}/gtest/include)
link_directories($ENV{GMOCK_HOME}/gtest/mybuild)


########## Create sanity checks for suffixTree. These should not be run on every compile, so we only build it and run manually
add_executable(suffixTreeSanityCheck suffixTreeSanityCheck.cpp)
target_link_libraries(suffixTreeSanityCheck gtest)
target_link_libraries(suffixTreeSanityCheck pthread)
target_link_libraries(suffixTreeSanityCheck suffixTreeLib)

########## Create sanity checks for linearization(Application 1).
add_executable(linearizationSanityCheck linearizationSanityCheck.cpp)
target_link_libraries(linearizationSanityCheck gtest)
target_link_libraries(linearizationSanityCheck pthread)
target_link_libraries(linearizationSanityCheck linearizationLib)

########## Create sanity checks for suffixArray(Application 2).
add_executable(suffixArraySanityCheck suffixArraySanityCheck.cpp)
target_link_libraries(suffixArraySanityCheck gtest)
target_link_libraries(suffixArraySanityCheck pthread)
target_link_libraries(suffixArraySanityCheck suffixArrayLib)