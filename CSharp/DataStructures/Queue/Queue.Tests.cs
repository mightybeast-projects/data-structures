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
    public void Non_First_Enqueued_Value_Should_Not_Be_Queue_Head()
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
}
