using NUnit.Framework;

namespace CSharp.Algorithms.BinarySearch;

[TestFixture]
public class BinarySearchTests
{
    [Test]
    [TestCase((int[])[1], 1)]
    [TestCase((int[])[1, 2], 2)]
    [TestCase((int[])[1, 12, 15, 25, 45, 90], 25)]
    public static void Assert_Item_Is_Found(int[] arr, int n)
    {
        Assert.That(BinarySearch.Search(arr, n), Is.True);
    }

    [Test]
    [TestCase((int[])[], 1)]
    [TestCase((int[])[1, 2, 4], 3)]
    public static void Assert_Item_Not_Found(int[] arr, int n)
    {
        Assert.That(BinarySearch.Search(arr, n), Is.False);
    }
}
