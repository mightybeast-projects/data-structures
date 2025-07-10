#include "selection-sort.hpp"

namespace selectionSort
{
    void sort(int* arr, int arrSize)
    {
        for (int i = 0; i < arrSize - 1; i++)
        {
            int minI = i;

            for (int j = i; j < arrSize; j++)
                if (arr[j] < arr[minI])
                    minI = j;

            int tmp = arr[i];
            arr[i] = arr[minI];
            arr[minI] = tmp;
        }
    }
}