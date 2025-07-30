#include "min-heap.hpp"
#include "testing-utils.hpp"
#include <gtest/gtest.h>

TEST(Min_Heap, Min_Heap_Is_Correct)
{
    minHeap::MinHeap heap;

    testingUtils::EXPECT_NULL(heap.remove());

    heap.insert(5);

    EXPECT_EQ(heap.length, 1);
    EXPECT_EQ(heap.remove(), 5);

    heap.insert(9);
    heap.insert(1);
    heap.insert(11);

    EXPECT_EQ(heap.length, 3);
    EXPECT_EQ(heap.peek(), 1);
    EXPECT_EQ(heap.remove(), 1);
    EXPECT_EQ(heap.length, 2);
    EXPECT_EQ(heap.peek(), 9);
}