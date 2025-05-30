using NUnit.Framework;

namespace CSharp.Algorithms.QuickSort;

[TestFixture]
public class QuickSortTests
{
    [Test]
    [TestCase((int[])[], (int[])[])]
    [TestCase((int[])[1], (int[])[1])]
    [TestCase((int[])[2, 1], (int[])[1, 2])]
    [TestCase((int[])[10, 2, 1], (int[])[1, 2, 10])]
    [TestCase((int[])[3, 5, 6, 1, 4], (int[])[1, 3, 4, 5, 6])]
    public void Array_Should_Be_Sorted(int[] arr, int[] expected)
    {
        Assert.That(QuickSort.Sort(arr), Is.EqualTo(expected));
    }
}
