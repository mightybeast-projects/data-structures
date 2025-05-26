namespace CSharp.DataStructures.LinkedList;

public class Node<T>(T value)
{
    public readonly T Value = value;
    public Node<T>? Next;
    public Node<T>? Prev;
}

public class LinkedList<T>
{
    public int Length;
    public Node<T>? Head;
    public Node<T>? Tail;

    public void Append(T value)
    {
        var node = new Node<T>(value);

        Head ??= node;

        if (Tail != null)
        {
            Tail.Next = node;
            node.Prev = Tail;
        }

        Tail = node;
        Length++;
    }

    public void Prepend(T value)
    {
        var node = new Node<T>(value);

        Tail ??= node;

        if (Head != null)
        {
            Head.Prev = node;
            node.Next = Head;
        }

        Head = node;
        Length++;
    }

    public T Get(int index)
    {
        var node = Head;

        for (int i = 0; i < index; i++)
            node = node?.Next;

        return node!.Value;
    }
}
