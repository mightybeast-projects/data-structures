namespace CSharp.Algorithms.LinearSearch;

public class LinearSearch
{
    public static bool Search(int[] arr, int n)
    {
        for (int i = 0; i < arr.Length; i++)
            if (arr[i] == n)
                return true;

        return false;
    }
}