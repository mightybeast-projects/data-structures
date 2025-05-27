namespace CSharp.DataStructures.Queue;

public class Node<T>(T value)
{
    public T Value = value;
    public Node<T>? Next;
}

public class Queue<T>
{
    public int Length;
    public Node<T>? Head;
    public Node<T>? Tail;

    public void Enqueue(T value)
    {
        Length++;

        var node = new Node<T>(value);

        Head ??= node;

        if (Tail != null)
            Tail.Next = node;

        Tail = node;
    }

    public T Dequeue()
    {
        var node = PeekNode();

        Length--;

        Head = Head!.Next;

        if (Length == 0)
            Tail = null;

        return node.Value;
    }

    public T Peek()
    {
        return PeekNode().Value;
    }

    private Node<T> PeekNode()
    {
        if (Head == null)
            throw new InvalidOperationException();

        return Head;
    }
}
