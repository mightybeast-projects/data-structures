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
}
