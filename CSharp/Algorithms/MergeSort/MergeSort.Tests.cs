using NUnit.Framework;

namespace CSharp.Algorithms.MergeSort;

[TestFixture]
public class MergeSortTests
{
    [Test]
    [TestCase((int[])[], (int[])[])]
    [TestCase((int[])[1], (int[])[1])]
    [TestCase((int[])[1, 3, 2], (int[])[1, 2, 3])]
    [TestCase((int[])[9, 4, 1, 6, 3, 2], (int[])[1, 2, 3, 4, 6, 9])]
    public void Assert_Array_Is_Sorted(int[] arr, int[] expected)
    {
        Assert.That(MergeSort.Sort(arr), Is.EqualTo(expected));
    }
}
