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
    public void Append_Should_Increment_List_Length()
    {
        list.Append(10);

        Assert.That(list.Length, Is.EqualTo(1));
    }

    [Test]
    public void First_Appended_Node_Should_Be_The_List_Head()
    {
        list.Append(10);

        Assert.That(list.Head?.Value, Is.EqualTo(10));
    }

    [Test]
    public void First_Appended_Node_Should_Be_The_List_Tail()
    {
        list.Append(10);

        Assert.That(list.Tail?.Value, Is.EqualTo(10));
    }

    [Test]
    public void Newly_Appended_Node_Should_Not_Be_The_List_Head()
    {
        list.Append(10);
        list.Append(2);

        Assert.That(list.Head?.Value, Is.EqualTo(10));
    }

    [Test]
    public void Newly_Appended_Node_Should_Be_The_List_Tail()
    {
        list.Append(10);
        list.Append(2);

        Assert.That(list.Tail?.Value, Is.EqualTo(2));
    }

    [Test]
    public void Newly_Appended_Node_Should_Link_To_The_Current_Tail_Of_The_List()
    {
        list.Append(10);
        list.Append(15);
        list.Append(2);

        Assert.That(list.Head?.Next?.Value, Is.EqualTo(15));
        Assert.That(list.Tail?.Prev?.Value, Is.EqualTo(15));
        Assert.That(list.Head?.Next?.Next?.Value, Is.EqualTo(2));
        Assert.That(list.Head?.Next?.Prev?.Value, Is.EqualTo(10));
    }

    [Test]
    public void Prepend_Should_Increment_List_Length()
    {
        list.Prepend(10);

        Assert.That(list.Length, Is.EqualTo(1));
    }

    [Test]
    public void First_Prepended_Node_Should_Be_The_List_Head()
    {
        list.Prepend(10);

        Assert.That(list.Head?.Value, Is.EqualTo(10));
    }

    [Test]
    public void First_Prepended_Node_Should_Be_The_List_Tail()
    {
        list.Prepend(10);

        Assert.That(list.Tail?.Value, Is.EqualTo(10));
    }

    [Test]
    public void Newly_Prepended_Node_Should_Not_Be_The_List_Tail()
    {
        list.Prepend(10);
        list.Prepend(2);

        Assert.That(list.Tail?.Value, Is.EqualTo(10));
    }

    [Test]
    public void Newly_Appended_Node_Should_Be_The_List_Head()
    {
        list.Prepend(10);
        list.Prepend(2);

        Assert.That(list.Head?.Value, Is.EqualTo(2));
    }

    [Test]
    public void Newly_Appended_Node_Should_Link_To_The_Current_Head_Of_The_List()
    {
        list.Prepend(10);
        list.Prepend(15);
        list.Prepend(2);

        Assert.That(list.Head?.Next?.Value, Is.EqualTo(15));
        Assert.That(list.Tail?.Prev?.Value, Is.EqualTo(15));
        Assert.That(list.Head?.Next?.Next?.Value, Is.EqualTo(10));
        Assert.That(list.Head?.Next?.Prev?.Value, Is.EqualTo(2));
    }

    [Test]
    public void Insert_At_With_Negative_Index_Should_Not_Insert_New_Value()
    {
        list.InsertAt(-1, 100);

        Assert.That(list.Length, Is.Zero);
        Assert.That(list.Head, Is.Null);
        Assert.That(list.Tail, Is.Null);
    }

    [Test]
    public void Insert_At_With_Out_Of_Range_Index_Should_Not_Insert_New_Value()
    {
        list.InsertAt(1, 100);

        Assert.That(list.Length, Is.Zero);
        Assert.That(list.Head, Is.Null);
        Assert.That(list.Tail, Is.Null);
    }

    [Test]
    public void Insert_At_With_Empty_List_Should_Prepend_New_Value()
    {
        list.InsertAt(0, 1);

        Assert.That(list.Length, Is.EqualTo(1));
        Assert.That(list.Head?.Value, Is.EqualTo(1));
        Assert.That(list.Tail?.Value, Is.EqualTo(1));
    }

    [Test]
    public void Insert_At_With_Zero_Index_Should_Prepend_New_Value()
    {
        list.InsertAt(0, 1);
        list.InsertAt(0, 2);

        Assert.That(list.Length, Is.EqualTo(2));
        Assert.That(list.Head?.Value, Is.EqualTo(2));
        Assert.That(list.Tail?.Value, Is.EqualTo(1));
        Assert.That(list.Head?.Next?.Value, Is.EqualTo(1));
        Assert.That(list.Tail?.Prev?.Value, Is.EqualTo(2));
    }

    [Test]
    public void Insert_At_With_Index_Equals_To_List_Length_Should_Append_New_Value()
    {
        list.InsertAt(0, 1);
        list.InsertAt(1, 2);

        Assert.That(list.Length, Is.EqualTo(2));
        Assert.That(list.Head?.Value, Is.EqualTo(1));
        Assert.That(list.Tail?.Value, Is.EqualTo(2));
        Assert.That(list.Head?.Next?.Value, Is.EqualTo(2));
        Assert.That(list.Tail?.Prev?.Value, Is.EqualTo(1));
    }

    [Test]
    public void Insert_At_Should_Insert_Value_At_Index()
    {
        list.Append(1);
        list.Append(4);
        list.Append(10);
        list.InsertAt(1, 2);

        Assert.That(list.Length, Is.EqualTo(4));
        Assert.That(list.Head?.Next?.Value, Is.EqualTo(2));
        Assert.That(list.Head?.Next?.Next?.Prev?.Value, Is.EqualTo(2));
        Assert.That(list.Head?.Next?.Next?.Next?.Value, Is.EqualTo(10));
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
