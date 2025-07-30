#include "merge-sort.hpp"

void sortRecurse(int arr[], int p, int r);
void merge(int arr[], int p, int q, int r);

namespace mergeSort
{
    void sort(int arr[], int arrSize)
    {
        sortRecurse(arr, 0, arrSize);
    }
}

void sortRecurse(int arr[], int p, int r)
{
    if (r - p <= 1)
        return;

    int q = (p + r) / 2;

    sortRecurse(arr, p, q);
    sortRecurse(arr, q, r);

    merge(arr, p, q, r);
}

void merge(int arr[], int p, int q, int r)
{
    int ln = q - p;
    int rn = r - q;

    int L[ln];
    int R[rn];

    for (int i = 0; i < ln; i++)
        L[i] = arr[p + i];

    for (int j = 0; j < rn; j++)
        R[j] = arr[q + j];

    int i = 0;
    int j = 0;
    int k = p;

    while (i < ln && j < rn)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < ln)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < rn)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}