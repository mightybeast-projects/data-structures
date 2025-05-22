namespace CSharp.Algorithms.BinarySearch;

public class BinarySearch
{
    public static bool Search(int[] arr, int n)
    {
        int l = 0;
        int r = arr.Length;

        while (l < r)
        {
            int m = l + (int)Math.Floor((r - l) / 2.0);

            if (arr[m] > n)
                r = m - 1;
            else if (arr[m] < n)
                l = m + 1;
            else
                return true;
        }

        return false;
    }
}
