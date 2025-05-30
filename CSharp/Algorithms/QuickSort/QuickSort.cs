using NUnit.Framework;

namespace CSharp.Algorithms.QuickSort;

[TestFixture]
public class QuickSort
{
    public static int[] Sort(int[] arr)
    {
        var res = arr;

        Quicksort(res, 0, arr.Length - 1);

        return res;
    }

    private static void Quicksort(int[] arr, int low, int high)
    {
        if (low >= high)
            return;

        var pivotIndex = Partition(arr, low, high);

        Quicksort(arr, low, pivotIndex - 1);
        Quicksort(arr, pivotIndex + 1, high);
    }

    private static int Partition(int[] arr, int low, int high)
    {
        var pivot = arr[high];
        var index = low - 1;

        for (var i = low; i < high; i++)
        {
            if (arr[i] <= pivot)
            {
                index++;
                (arr[index], arr[i]) = (arr[i], arr[index]);
            }
        }

        index++;
        arr[high] = arr[index];
        arr[index] = pivot;

        return index;
    }
}
