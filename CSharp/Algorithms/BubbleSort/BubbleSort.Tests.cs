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
    public void Assert_Array_Is_Sorted()
    {
        int[] arr = [9, 4, 1, 6, 3, 2];
        int[] expected = [1, 2, 3, 4, 6, 9];

        Assert.That(BubbleSort.Sort(arr), Is.EqualTo(expected));
    }
}
