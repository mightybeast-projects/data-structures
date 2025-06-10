#pragma once

#include <vector>

namespace minHeap
{
    struct MinHeap
    {
        int length = 0;

        void insert(int value);
        int remove();
        int peek();

    private:
        std::vector<int> arr = {};
        void heapifyUp(int nodeIndex);
        void heapifyDown(int nodeIndex);
    };
}