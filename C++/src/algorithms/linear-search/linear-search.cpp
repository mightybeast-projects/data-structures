#include "linear-search.hpp"

namespace linearSearch
{
    bool search(int *arr, int key, int arrSize)
    {
        for (int i = 0; i < arrSize; i++)
            if (arr[i] == key)
                return true;

        return false;
    }
}