cmake_minimum_required(VERSION 3.12)

project(C-DS)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS
    src/**/*.c
) 
 
add_executable(tests ${SOURCE_FILES})

target_include_directories(tests PRIVATE
    src/algorithms
    src/data-structures
    src/noob-stuff
)