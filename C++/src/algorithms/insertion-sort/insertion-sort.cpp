#include "insertion-sort.hpp"

namespace insertionSort
{
    void sort(int *arr, int arrSize)
    {
        for (int i = 1; i < arrSize; i++)
        {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }
    }
}