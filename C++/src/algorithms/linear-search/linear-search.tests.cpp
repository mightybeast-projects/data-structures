#include "linear-search.h"

namespace LinearSearch
{
    bool linearSearch(int *arr, int key, int arrSize)
    {
        for (int i = 0; i < arrSize; i++)
            if (arr[i] == key)
                return true;
    }
}