using NUnit.Framework;

namespace CSharp.Algorithms.LinearSearch;

[TestFixture]
public class LinearSearchTests
{
    [Test]
    [TestCase((int[])[0], 0)]
    [TestCase((int[])[0, 1], 1)]
    [TestCase((int[])[4, 564, 2, 12, 67, 3, 75, 223], 75)]
    public void Assert_Item_Is_Found(int[] arr, int n)
    {
        Assert.That(LinearSearch.Search(arr, n), Is.True);
    }

    [Test]
    [TestCase((int[])[0], -1)]
    [TestCase((int[])[0, 1], 2)]
    [TestCase((int[])[4, 564, 2, 12, 67, 3, 75, 223], 76)]
    public void Assert_Item_Not_Found(int[] arr, int n)
    {
        Assert.That(LinearSearch.Search(arr, n), Is.False);
    }
}
