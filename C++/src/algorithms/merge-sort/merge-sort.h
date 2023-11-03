namespace MergeSort
{
    void mergeSort(int *arr, int arrSize);
}

namespace
{
    void mergeSortRecurse(int *arr, int p, int r);

    void merge(int *arr, int p, int q, int r);
}