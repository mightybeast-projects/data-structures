using NUnit.Framework;

namespace CSharp.DataStructures.LinkedList;

[TestFixture]
public class LinkedListTests
{
    private LinkedList<int> list;

    [SetUp]
    public void SetUp() => list = new LinkedList<int>();

    [Test]
    public void New_List_Should_Have_Zero_Length() => Assert.That(list.Length, Is.Zero);

    [Test]
    public void New_List_Should_Have_Null_Head() => Assert.That(list.Head, Is.Null);

    [Test]
    public void New_List_Should_Have_Null_Tail() => Assert.That(list.Tail, Is.Null);
}
