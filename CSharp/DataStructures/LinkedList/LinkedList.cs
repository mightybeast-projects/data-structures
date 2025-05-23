namespace CSharp.DataStructures.LinkedList;

public class Node<T>(T value)
{
    public readonly T Value = value;
    public Node<T>? Child;
    public Node<T>? Parent;
}

public class LinkedList<T>
{
    public int Length;
    public Node<T>? Head;
    public Node<T>? Tail;

    public T Get(int index)
    {
        var node = Head;

        for (int i = 0; i < index; i++)
            node = node?.Child;

        return node!.Value;
    }

    public void Append(T value)
    {
        var node = new Node<T>(value);

        Head ??= node;

        if (Tail != null)
        {
            Tail.Child = node;
            node.Parent = Tail;
        }

        Tail = node;
        Length++;
    }
}
