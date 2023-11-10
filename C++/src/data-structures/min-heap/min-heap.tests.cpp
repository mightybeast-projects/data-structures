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

        heap.insert(5);

        EXPECT_EQ(heap.length, 1);

        heap.insert(9);
        heap.insert(1);

        EXPECT_EQ(heap.length, 3);
        EXPECT_EQ(heap.peek(), 1);
    }
}