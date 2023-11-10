#include <math.h>
#include "min-heap.h"

using namespace std;

namespace MinHeap
{
    void MinHeap::insert(int value)
    {
        arr.push_back(value);
        heapifyUp(arr.size() - 1);
        length++;
    }

    int MinHeap::peek()
    {
        return arr[0];
    }

    void MinHeap::heapifyUp(int nodeIndex)
    {
        if (nodeIndex == 0)
            return;

        int parentIndex = floor((nodeIndex - 1) / 2);

        int nodeValue = arr[nodeIndex];
        int parentValue = arr[parentIndex];

        if (nodeValue < parentValue)
        {
            arr[nodeIndex] = parentValue;
            arr[parentIndex] = nodeValue;
            heapifyUp(parentIndex);
        }
    }
}