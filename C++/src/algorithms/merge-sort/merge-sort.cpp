#include "merge-sort.hpp"

namespace MergeSort
{
    void mergeSort(int *arr, int arrSize)
    {
        mergeSortRecurse(arr, 0, arrSize);
    }
}

namespace
{
    void mergeSortRecurse(int *arr, int p, int r)
    {
        if (p >= r)
            return;

        int q = (p + r) / 2;

        mergeSortRecurse(arr, p, q);
        mergeSortRecurse(arr, q + 1, r);

        merge(arr, p, q, r);
    }

    void merge(int *arr, int p, int q, int r)
    {
        int ln = q - p + 1;
        int rn = r - q;

        int L[ln];
        int R[rn];

        for (int i = 0; i < ln; i++)
            L[i] = arr[p + i];

        for (int j = 0; j < rn; j++)
            R[j] = arr[q + j + 1];

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
}