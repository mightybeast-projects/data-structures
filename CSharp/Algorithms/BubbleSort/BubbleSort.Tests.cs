using NUnit.Framework;

namespace CSharp.Algorithms.BubbleSort;

[TestFixture]
public class BubbleSortTests
{
    [Test]
    public void Assert_Empty_Array_Is_The_Same()
    {
        Assert.That(BubbleSort.Sort([]), Is.EqualTo((int[])[]));
    }

    [Test]
    [TestCase((int[])[1], (int[])[1])]
    [TestCase((int[])[1, 3, 2], (int[])[1, 2, 3])]
    [TestCase((int[])[9, 4, 1, 6, 3, 2], (int[])[1, 2, 3, 4, 6, 9])]
    public void Assert_Array_Is_Sorted(int[] arr, int[] expected)
    {
        Assert.That(BubbleSort.Sort(arr), Is.EqualTo(expected));
    }
}
