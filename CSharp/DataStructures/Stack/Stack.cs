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

    public void Push(T value)
    {
        Size++;

        var node = new Node<T>(value);

        if (Head != null)
            node.Prev = Head;

        Head = node;
    }

    public T Pop()
    {
        var head = PeekHead();

        Size--;

        Head = head.Prev;

        if (Size == 0)
            Head = null;

        return head.Value;
    }

    public T Peek()
    {
        return PeekHead().Value;
    }

    private Node<T> PeekHead()
    {
        if (Head == null)
            throw new InvalidOperationException();

        return Head;
    }
}
