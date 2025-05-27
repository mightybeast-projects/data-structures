namespace CSharp.DataStructures.Stack;

public class Node<T>(T value)
{
    public T Value = value;
    public Node<T>? Prev;
}

public class Stack<T>
{
    public int Size;
    public Node<T>? Head;
    public Node<T>? Tail;

    public void Push(T value)
    {
        Size++;

        var node = new Node<T>(value);

        if (Tail != null)
            node.Prev = Tail;

        Tail ??= node;

        Head = node;
    }
}
