#include "bubble-sort.h"

namespace BubbleSort
{
    void bubbleSort(int (&arr)[], int size)
    {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size - 1 - i; j++)
                bubbleSwap(arr, j);
    }
}

namespace
{
    void bubbleSwap(int (&arr)[], int i)
    {
        if (arr[i] < arr[i + 1])
            return;

        int tmp = arr[i + 1];
        arr[i + 1] = arr[i];
        arr[i] = tmp;
    }
}