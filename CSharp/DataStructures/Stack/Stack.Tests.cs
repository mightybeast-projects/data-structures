using NUnit.Framework;

namespace CSharp.DataStructures.Stack;

[TestFixture]
public class StackTests
{
    private Stack<int> stack;

    [SetUp]
    public void SetUp() => stack = new Stack<int>();

    [Test]
    public void New_Stack_Should_Have_Zero_Size() => Assert.That(stack.Size, Is.Zero);

    [Test]
    public void Push_Should_Increment_Stack_Size()
    {
        stack.Push(10);

        Assert.That(stack.Size, Is.EqualTo(1));
    }

    [Test]
    public void First_Pushed_Value_Should_Be_Stack_Head()
    {
        stack.Push(10);

        Assert.That(stack.Head?.Value, Is.EqualTo(10));
    }

    [Test]
    public void Newly_Pushed_Value_Should_Be_Stack_Head()
    {
        stack.Push(10);
        stack.Push(20);

        Assert.That(stack.Head?.Value, Is.EqualTo(20));
    }

    [Test]
    public void Push_Should_Link_Nodes()
    {
        stack.Push(10);
        stack.Push(20);

        Assert.That(stack.Head?.Prev?.Value, Is.EqualTo(10));
    }

    [Test]
    public void Pop_On_Empty_Stack_Should_Throw_Invalid_Operation_Exception()
    {
        Assert.Throws<InvalidOperationException>(() => stack.Pop());
    }

    [Test]
    public void Pop_Should_Decrement_Size()
    {
        stack.Push(10);

        stack.Pop();

        Assert.That(stack.Size, Is.Zero);
    }

    [Test]
    public void Pop_On_Last_Value_Should_Reset_Stack_Head()
    {
        stack.Push(10);

        stack.Pop();

        Assert.That(stack.Head, Is.Null);
    }

    [Test]
    public void Pop_Should_Return_Head_Value()
    {
        stack.Push(2);
        stack.Push(20);
        stack.Push(14);

        var res = stack.Pop();

        Assert.That(res, Is.EqualTo(14));
    }

    [Test]
    public void Pop_Should_Shift_Stack()
    {
        stack.Push(2);
        stack.Push(20);
        stack.Push(14);

        stack.Pop();

        Assert.That(stack.Head?.Value, Is.EqualTo(20));
    }

    [Test]
    public void Peek_On_Empty_Stack_Should_Throw_Invalid_Operation_Exception()
    {
        Assert.Throws<InvalidOperationException>(() => stack.Peek());
    }

    [Test]
    public void Peek_Should_Return_Current_Stack_Head()
    {
        stack.Push(10);

        Assert.That(stack.Peek(), Is.EqualTo(10));
    }
}
