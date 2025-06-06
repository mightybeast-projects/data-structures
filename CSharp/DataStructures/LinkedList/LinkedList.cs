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

    public void InsertAt(int index, T value)
    {
        ValidateIndex(index);

        if (index == 0)
        {
            Prepend(value);
            return;
        }

        if (index == Length)
        {
            Append(value);
            return;
        }

        var indexNode = GetAt(index);
        var node = new Node<T>(value) { Prev = indexNode.Prev, Next = indexNode };

        indexNode.Prev!.Next = node;
        indexNode.Prev = node;

        Length++;
    }

    public T Remove(T value)
    {
        var node = Head ?? throw new InvalidOperationException();

        while (node.Next != null && !node!.Value!.Equals(value))
            node = node.Next;

        return RemoveNode(node);
    }

    public T RemoveAt(int index)
    {
        ValidateIndex(index);

        return RemoveNode(GetAt(index));
    }

    public T Get(int index)
    {
        ValidateIndex(index);

        return GetAt(index).Value;
    }

    private Node<T> GetAt(int index)
    {
        var node = Head;

        for (int i = 0; i < index; i++)
            node = node?.Next;

        return node!;
    }

    private T RemoveNode(Node<T> node)
    {
        Length--;

        if (Length == 0)
        {
            Head = null;
            Tail = null;
            return node.Value;
        }

        if (node.Prev != null)
            node.Prev.Next = node.Next;

        if (node.Next != null)
            node.Next.Prev = node.Prev;

        if (node == Head)
            Head = node.Next;

        if (node == Tail)
            Tail = node.Prev;

        return node.Value;
    }

    private void ValidateIndex(int index)
    {
        if (index < 0 || index > Length)
            throw new IndexOutOfRangeException();
    }
}
