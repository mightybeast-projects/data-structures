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
    public void First_Pushed_Value_Should_Be_Stack_Tail()
    {
        stack.Push(10);

        Assert.That(stack.Tail?.Value, Is.EqualTo(10));
    }

    [Test]
    public void First_Pushed_Value_Should_Remain_To_Be_Stack_Tail()
    {
        stack.Push(10);
        stack.Push(20);

        Assert.That(stack.Tail?.Value, Is.EqualTo(10));
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
}
