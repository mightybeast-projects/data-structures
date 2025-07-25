#include "binary-search.h"

bool binarySearch(int arr[], int size, int value)
{
    int l = 0;
    int h = size - 1;

    int m;

    while (l <= h)
    {
        m = l + (h - l) / 2;

        if (value < arr[m])
            h = m - 1;
        else if (value > arr[m])
            l = m + 1;
        else
            return true;
    }

    return false;
}