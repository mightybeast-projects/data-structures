#include "selection-sort.h"

namespace SelectionSort
{
    void selectionSort(int *arr, int arrSize)
    {
        for (int i = 0; i < arrSize - 1; i++)
        {
            int minI = i;

            for (int j = i; j < arrSize; j++)
            {
                if (arr[j] < arr[minI])
                    minI = j;
            }

            selectionSwap(arr, i, minI);
        }
    }
}

namespace
{
    void selectionSwap(int *arr, int i, int j)
    {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}