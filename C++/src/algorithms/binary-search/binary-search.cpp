#include <math.h>
#include "binary-search.hpp"

namespace BinarySearch
{
    int binarySearch(int *arr, int arrSize, int item)
    {
        int l = 0;
        int r = arrSize - 1;

        while (l <= r)
        {
            int m = floor(l + r / 2);

            if (arr[m] < item)
                l = m + 1;
            else if (arr[m] > item)
                r = m;
            else
                return m;
        }

        return NULL;
    }
}