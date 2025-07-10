#include "min-heap.hpp"
#include <math.h>

namespace minHeap
{
    using namespace std;

    void MinHeap::insert(int value)
    {
        arr.push_back(value);
        heapifyUp(arr.size() - 1);
        length++;
    }

    int MinHeap::remove()
    {
        if (length == 0)
            return int();

        int node = arr[0];
        length--;

        if (length == 0)
        {
            arr = {};
            return node;
        }

        arr[0] = arr[length];
        heapifyDown(0);

        return node;
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

        int node = arr[nodeIndex];
        int parent = arr[parentIndex];

        if (node < parent)
        {
            arr[nodeIndex] = parent;
            arr[parentIndex] = node;
            heapifyUp(parentIndex);
        }
    }
    void MinHeap::heapifyDown(int nodeIndex)
    {
        int leftChildIndex = 2 * nodeIndex + 1;
        int rihgtChildIndex = 2 * nodeIndex + 2;

        if (nodeIndex >= length || leftChildIndex >= length)
            return;

        int node = arr[nodeIndex];
        int leftChild = arr[leftChildIndex];
        int rightChild = arr[rihgtChildIndex];

        if (leftChild > rightChild && node > rightChild)
        {
            arr[nodeIndex] = rightChild;
            arr[rihgtChildIndex] = node;
            heapifyDown(rihgtChildIndex);
        } else if (rightChild > leftChild && node > leftChild)
        {
            arr[nodeIndex] = leftChild;
            arr[leftChildIndex] = node;
            heapifyDown(leftChildIndex);
        }
    }
}