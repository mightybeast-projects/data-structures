#include <stdbool.h>

bool linearSearch(int arr[], int n, int v)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == v)
            return true;

    return false;
}