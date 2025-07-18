#include "linear-search.h"

bool linearSearch(int arr[], int n, int value)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == value)
            return true;

    return false;
}