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

    [Test]
    public void First_Appended_Node_Should_Be_List_Head()
    {
        list.Append(10);

        Assert.That(list.Head?.Value, Is.EqualTo(10));
    }

    [Test]
    public void First_Appended_Node_Should_Be_List_Tail()
    {
        list.Append(10);

        Assert.That(list.Tail?.Value, Is.EqualTo(10));
    }

    [Test]
    public void Append_Should_Increment_List_Length()
    {
        list.Append(10);

        Assert.That(list.Length, Is.EqualTo(1));
    }

    [Test]
    public void Newly_Appended_Node_Should_Not_Be_List_Head()
    {
        list.Append(10);
        list.Append(2);

        Assert.That(list.Head?.Value, Is.EqualTo(10));
    }

    [Test]
    public void Newly_Appended_Node_Should_Be_List_Tail()
    {
        list.Append(10);
        list.Append(2);

        Assert.That(list.Tail?.Value, Is.EqualTo(2));
    }

    [Test]
    public void Newly_Appended_Node_Should_Link_With_Current_Tail()
    {
        list.Append(10);
        list.Append(15);
        list.Append(2);

        Assert.That(list.Head?.Child?.Value, Is.EqualTo(15));
        Assert.That(list.Tail?.Parent?.Value, Is.EqualTo(15));
        Assert.That(list.Head?.Child?.Child?.Value, Is.EqualTo(2));
        Assert.That(list.Head?.Child?.Parent?.Value, Is.EqualTo(10));
    }

    [Test]
    public void Get_Should_Return_Value_By_Node_Index()
    {
        list.Append(10);
        list.Append(3);
        list.Append(5);

        Assert.That(list.Get(0), Is.EqualTo(10));
        Assert.That(list.Get(1), Is.EqualTo(3));
        Assert.That(list.Get(2), Is.EqualTo(5));
    }
}
