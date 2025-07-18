#include "quick-sort.h"

void quickSortRecurse(int arr[], int l, int h);
int partition(int arr[], int l, int h);

void quickSort(int arr[], int n)
{
    int l = 0;
    int h = n - 1;

    quickSortRecurse(arr, l, h);
}

void quickSortRecurse(int arr[], int l, int h)
{
    if (l >= h)
        return;

    int pIndex = partition(arr, l, h);

    quickSortRecurse(arr, l, pIndex - 1);
    quickSortRecurse(arr, pIndex + 1, h);
}

int partition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int pIndex = l;

    for (int i = l; i < h; i++)
    {
        if (arr[i] <= pivot)
        {
            int current = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = current;
            pIndex++;
        }
    }

    int last = arr[h];
    arr[h] = arr[pIndex];
    arr[pIndex] = last;

    return pIndex;
}