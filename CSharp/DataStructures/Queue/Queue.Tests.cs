using NUnit.Framework;

namespace CSharp.DataStructures.Queue;

[TestFixture]
public class QueueTests
{
    private Queue<int> queue;

    [SetUp]
    public void SetUp() => queue = new Queue<int>();

    [Test]
    public void New_Queue_Should_Have_Zero_Length() => Assert.That(queue.Length, Is.Zero);

    [Test]
    public void Enqueue_Should_Increment_Length()
    {
        queue.Enqueue(10);

        Assert.That(queue.Length, Is.EqualTo(1));
    }

    [Test]
    public void First_Enqueued_Value_Should_Be_Queue_Head()
    {
        queue.Enqueue(10);

        Assert.That(queue.Head?.Value, Is.EqualTo(10));
    }

    [Test]
    public void First_Enqueued_Value_Should_Be_Queue_Tail()
    {
        queue.Enqueue(10);

        Assert.That(queue.Tail?.Value, Is.EqualTo(10));
    }

    [Test]
    public void First_Enqueued_Value_Should_Remain_To_Be_Queue_Head()
    {
        queue.Enqueue(10);
        queue.Enqueue(2);

        Assert.That(queue.Head?.Value, Is.EqualTo(10));
    }

    [Test]
    public void Newly_Enqueued_Value_Should_Be_Queue_Tail()
    {
        queue.Enqueue(10);
        queue.Enqueue(2);

        Assert.That(queue.Tail?.Value, Is.EqualTo(2));
    }

    [Test]
    public void Enqueue_Should_Link_Nodes()
    {
        queue.Enqueue(10);
        queue.Enqueue(2);

        Assert.That(queue.Head?.Next?.Value, Is.EqualTo(2));
    }

    [Test]
    public void Dequeue_On_Empty_List_Should_Throw_Invalid_Operation_Exception()
    {
        Assert.Throws<InvalidOperationException>(() => queue.Dequeue());
    }

    [Test]
    public void Dequeue_Should_Decrement_Queue_Length()
    {
        queue.Enqueue(10);
        queue.Enqueue(2);
        queue.Enqueue(4);

        queue.Dequeue();

        Assert.That(queue.Length, Is.EqualTo(2));
    }

    [Test]
    public void Dequeue_Of_Last_Value_Should_Reset_Queue_Head_And_Tail()
    {
        queue.Enqueue(10);

        queue.Dequeue();

        Assert.That(queue.Head, Is.Null);
        Assert.That(queue.Tail, Is.Null);
    }

    [Test]
    public void Dequeue_Should_Return_Head_Value()
    {
        queue.Enqueue(10);
        queue.Enqueue(2);
        queue.Enqueue(4);

        var res = queue.Dequeue();

        Assert.That(res, Is.EqualTo(10));
    }

    [Test]
    public void Dequeue_Should_Shift_Queue()
    {
        queue.Enqueue(10);
        queue.Enqueue(2);
        queue.Enqueue(4);

        queue.Dequeue();

        Assert.That(queue.Head?.Value, Is.EqualTo(2));
    }

    [Test]
    public void Peek_Should_Return_Current_Queue_Head()
    {
        queue.Enqueue(1);
        queue.Enqueue(2);
        queue.Enqueue(3);

        Assert.That(queue.Peek(), Is.EqualTo(1));
    }

    [Test]
    public void Peek_On_Empty_Queue_Should_Throw_Invalid_Operation_Exception()
    {
        Assert.Throws<InvalidOperationException>(() => queue.Peek());
    }
}
