cmake_minimum_required(VERSION 3.12)

project(Project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS
    src/**/*.cpp
    src/**/*.h
)

add_executable(tests ${SOURCE_FILES})

target_include_directories(tests PRIVATE
    src/utils
    src/data-structures/binary-tree
    src/data-structures/queue
)

target_link_libraries(tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)