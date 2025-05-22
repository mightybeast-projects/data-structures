using NUnit.Framework;

namespace CSharp.Algorithms.LinearSearch;

[TestFixture]
public class LinearSearchTests
{
    private static readonly object[] trueCases =
    [
        new object[] { new int[] { 0 }, 0 },
        new object[] { new int[] { 0, 1 }, 1 },
        new object[] { new int[] { 4, 564, 2, 12, 67, 3, 75, 223 }, 75 },
    ];

    private static readonly object[] falseCases =
    [
        new object[] { new int[] { 0 }, -1 },
        new object[] { new int[] { 0 }, 1 },
        new object[] { new int[] { 4, 564, 2, 12, 67, 3, 75, 223 }, 76 },
    ];

    [TestCaseSource(nameof(trueCases))]
    public void Assert_Item_Is_Found(int[] arr, int n) =>
        Assert.That(LinearSearch.Search(arr, n), Is.True);

    [TestCaseSource(nameof(falseCases))]
    public void Assert_Item_Not_Found(int[] arr, int n) =>
        Assert.That(LinearSearch.Search(arr, n), Is.False);
}
