using CSharp.Algorithms.LinearSearch;
using NUnit.Framework;

namespace CSharp;

public class Tests
{
    [TestCase(new int[] { 0 }, 0, ExpectedResult = true)]
    [TestCase(new int[] { 0 }, 1, ExpectedResult = false)]
    [TestCase(new int[] { 0, 1 }, 1, ExpectedResult = true)]
    [TestCase(new int[] { 0, 1, 2 }, 2, ExpectedResult = true)]
    [TestCase(new int[] { 4, 564, 2, 12, 67, 3, 75, 223 }, 75, ExpectedResult = true)]
    public bool TestLinearSearch(int[] arr, int n) =>
        LinearSearch.Search(arr, n);
}