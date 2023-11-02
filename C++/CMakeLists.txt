cmake_minimum_required(VERSION 3.12) # version can be different

project(Project)

enable_testing() #to  discover tests in test explorer 

add_subdirectory(googletest) # add googletest subdirectory

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

add_executable(
    mytests

    src/algorithms/bubble_sort/bubble_sort.cpp
    src/algorithms/bubble_sort/bubble_sort.tests.cpp
)

target_link_libraries(
    mytests
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(mytests) # discovers tests by asking the compiled test executable to enumerate its tests