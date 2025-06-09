namespace mergeSort
{
    void sort(int *arr, int arrSize);
}

namespace
{
    void sortRecurse(int *arr, int p, int r);
    void merge(int *arr, int p, int q, int r);
}