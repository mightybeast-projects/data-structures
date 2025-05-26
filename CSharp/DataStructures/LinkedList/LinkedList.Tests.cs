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
    public void Insert_At_With_Out_Of_Range_Index_Should_Throw_Index_Out_Of_Range_Exception()
    {
        Assert.Throws<IndexOutOfRangeException>(() => list.InsertAt(1, 100));
        Assert.Throws<IndexOutOfRangeException>(() => list.InsertAt(-1, 100));

        Assert.That(list.Length, Is.Zero);
        Assert.That(list.Head, Is.Null);
        Assert.That(list.Tail, Is.Null);
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
    public void Remove_Should_Decrement_List_Length()
    {
        list.Append(4);
        list.Remove(4);

        Assert.That(list.Length, Is.EqualTo(0));
    }

    [Test]
    public void Remove_On_One_Sized_List_Should_Set_Head_And_Tail_To_Null()
    {
        list.Append(4);

        var res = list.Remove(4);

        Assert.That(res, Is.EqualTo(4));
        Assert.That(list.Head, Is.Null);
        Assert.That(list.Tail, Is.Null);
    }

    [Test]
    public void Remove_Should_Throw_Invalid_Operation_Exception_If_List_Does_Not_Contain_Value()
    {
        Assert.Throws<InvalidOperationException>(() => list.Remove(3));

        Assert.That(list.Length, Is.EqualTo(0));
    }

    [Test]
    public void Remove_Should_Remove_Specified_Value_From_List()
    {
        list.Append(3);
        list.Append(6);
        list.Append(10);

        var res = list.Remove(6);

        Assert.That(res, Is.EqualTo(6));
        Assert.That(list.Length, Is.EqualTo(2));
        Assert.That(list.Head?.Value, Is.EqualTo(3));
        Assert.That(list.Head?.Next?.Value, Is.EqualTo(10));
        Assert.That(list.Tail?.Value, Is.EqualTo(10));
        Assert.That(list.Tail?.Prev?.Value, Is.EqualTo(3));
    }

    [Test]
    public void Remove_Should_Remove_Value_And_Assign_New_Head_If_Removed_Value_Was_First()
    {
        list.Append(3);
        list.Append(6);
        list.Append(10);

        var res = list.Remove(3);

        Assert.That(res, Is.EqualTo(3));
        Assert.That(list.Length, Is.EqualTo(2));
        Assert.That(list.Head?.Value, Is.EqualTo(6));
        Assert.That(list.Head?.Next?.Value, Is.EqualTo(10));
    }

    [Test]
    public void Remove_Should_Remove_Value_And_Assign_New_Tail_If_Removed_Value_Was_Last()
    {
        list.Append(3);
        list.Append(6);
        list.Append(10);

        var res = list.Remove(10);

        Assert.That(res, Is.EqualTo(10));
        Assert.That(list.Length, Is.EqualTo(2));
        Assert.That(list.Tail?.Value, Is.EqualTo(6));
        Assert.That(list.Tail?.Prev?.Value, Is.EqualTo(3));
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

    [Test]
    public void Get_Should_Throw_Index_Out_Of_Range_Exception_If_Index_Is_Out_Of_Range()
    {
        list.Append(1);

        Assert.Throws<IndexOutOfRangeException>(() => list.Get(-1));
        Assert.Throws<IndexOutOfRangeException>(() => list.Get(2));
    }
}
