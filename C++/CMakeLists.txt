cmake_minimum_required(VERSION 3.12) # version can be different

project(Project)

enable_testing() #to  discover tests in test explorer 

add_subdirectory(googletest) # add googletest subdirectory

include_directories(
    googletest/include
    src/utils
    src/data-structures/binary-tree
    src/data-structures/queue
) # this is so we can #include <gtest/gtest.h>

add_executable(
    mytests

    src/utils/testing-utils.h

    src/algorithms/linear-search/linear-search.cpp
    src/algorithms/linear-search/linear-search.h
    src/algorithms/linear-search/linear-search.tests.cpp

    src/algorithms/bubble-sort/bubble-sort.cpp
    src/algorithms/bubble-sort/bubble-sort.tests.cpp

    src/algorithms/insertion-sort/insertion-sort.cpp
    src/algorithms/insertion-sort/insertion-sort.h
    src/algorithms/insertion-sort/insertion-sort.tests.cpp

    src/algorithms/selection-sort/selection-sort.cpp
    src/algorithms/selection-sort/selection-sort.h
    src/algorithms/selection-sort/selection-sort.tests.cpp

    src/algorithms/merge-sort/merge-sort.cpp
    src/algorithms/merge-sort/merge-sort.h
    src/algorithms/merge-sort/merge-sort.tests.cpp

    src/algorithms/binary-search/binary-search.cpp
    src/algorithms/binary-search/binary-search.h
    src/algorithms/binary-search/binary-search.tests.cpp

    src/algorithms/bt-bfs/bt-bfs.tests.cpp
    src/algorithms/bt-bfs/bt-bfs.h

    src/algorithms/bt-dfs/bt-dfs.tests.cpp
    src/algorithms/bt-dfs/bt-dfs.h

    src/data-structures/stack/stack.tests.cpp

    src/data-structures/queue/queue.h
    src/data-structures/queue/queue.tests.cpp

    src/data-structures/linked-list/linked-list.tests.cpp

    src/data-structures/binary-tree/binary-tree.tests.cpp
)

target_link_libraries(
    mytests
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(mytests) # discovers tests by asking the compiled test executable to enumerate its tests