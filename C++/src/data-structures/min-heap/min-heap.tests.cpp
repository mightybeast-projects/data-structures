#include <gtest/gtest.h>
#include "testing-utils.h"
#include "min-heap.h"

using namespace TestingUtils;
using namespace MinHeap;

namespace MinHeap
{
    TEST(MinHeapTests, MinHeap_IsCorrect)
    {
        MinHeap heap;

        EXPECT_NULL(heap.remove());

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
}