namespace CSharp.Algorithms.MergeSort;

public class MergeSort
{
    public static int[] Sort(int[] arr)
    {
        var res = arr;

        SortRecurse(res, 0, res.Length);

        return res;
    }

    private static void SortRecurse(int[] arr, int p, int r)
    {
        if (r - p <= 1)
            return;

        int q = (p + r) / 2;

        SortRecurse(arr, p, q);
        SortRecurse(arr, q, r);

        Merge(arr, p, q, r);
    }

    private static void Merge(int[] arr, int p, int q, int r)
    {
        int ln = q - p;
        int rn = r - q;

        int[] L = new int[ln];
        int[] R = new int[rn];

        for (int i = 0; i < ln; i++)
            L[i] = arr[p + i];

        for (int j = 0; j < rn; j++)
            R[j] = arr[q + j];

        int ii = 0;
        int jj = 0;
        int k = p;

        while (ii < ln && jj < rn)
        {
            if (L[ii] <= R[jj])
                arr[k++] = L[ii++];
            else
                arr[k++] = R[jj++];
        }

        while (ii < ln)
            arr[k++] = L[ii++];

        while (jj < rn)
            arr[k++] = R[jj++];
    }
}
