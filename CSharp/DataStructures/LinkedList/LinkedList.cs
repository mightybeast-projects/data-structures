namespace CSharp.DataStructures.LinkedList;

public class Node<T>
{
    readonly T? value;
    Node<T>? child;
    Node<T>? parent;
}

public class LinkedList<T>
{
    public int Length;
    public Node<T>? Head;
    public Node<T>? Tail;

    public LinkedList() { }
}
