#include "bubble_sort.h"

namespace BubbleSort
{
    void bubble_sort(int (&arr)[], int size)
    {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size - 1 - i; j++)
                bubble_swap(arr, j);
    }
}

namespace
{
    void bubble_swap(int (&arr)[], int i)
    {
        if (arr[i] < arr[i + 1])
            return;

        int tmp = arr[i + 1];
        arr[i + 1] = arr[i];
        arr[i] = tmp;
    }
}