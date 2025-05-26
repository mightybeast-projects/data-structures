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
        return GetAt(index).Value;
    }

    public void InsertAt(int index, T value)
    {
        if (index < 0 || index > Length)
            return;

        if (index == 0)
            Prepend(value);
        else if (index == Length)
            Append(value);
        else
        {
            var indexNode = GetAt(index);
            var node = new Node<T>(value);

            node.Prev = indexNode.Prev;
            node.Next = indexNode;
            indexNode.Prev!.Next = node;
            indexNode.Prev = node;

            Length++;
        }
    }

    private Node<T> GetAt(int index)
    {
        var node = Head;

        for (int i = 0; i < index; i++)
            node = node?.Next;

        return node!;
    }
}
