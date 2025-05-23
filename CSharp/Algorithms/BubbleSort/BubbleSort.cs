namespace CSharp.Algorithms.BubbleSort;

public class BubbleSort
{
    public static int[] Sort(int[] arr)
    {
        int[] res = arr;

        for (int i = 0; i < arr.Length; i++)
        {
            for (int j = 0; j < arr.Length - i - 1; j++)
            {
                if (res[j] > res[j + 1])
                {
                    int next = res[j + 1];
                    res[j + 1] = res[j];
                    res[j] = next;
                }
            }
        }

        return res;
    }
}
