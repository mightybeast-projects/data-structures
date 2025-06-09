#pragma once
namespace linkedListNode
{
    template <typename T>
    struct Node
    {
        T value;
        Node<T> *next;
        Node<T> *prev;
    };
}
