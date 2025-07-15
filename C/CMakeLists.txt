cmake_minimum_required(VERSION 3.12)

project(C-DS)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#cmd
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS
    src/**/*.c
) 
 
add_executable(c-cmd ${SOURCE_FILES})


#lib
add_library(c-ds STATIC
    ${SOURCE_FILES}
)

file(GLOB_RECURSE INCLUDE_DIRS LIST_DIRECTORIES true "${CMAKE_CURRENT_SOURCE_DIR}/src/*")

foreach(dir ${INCLUDE_DIRS})
	if(IS_DIRECTORY ${dir})
		target_include_directories(c-ds PUBLIC ${dir})
	endif()
endforeach()


#tests
add_subdirectory(test)