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
    int i = l;

    for (int j = l; j < h; j++)
    {
        if (arr[j] <= pivot)
        {
            int tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
            i++;
        }
    }

    int tmp = arr[h];
    arr[h] = arr[i];
    arr[i] = tmp;

    return i;
}