#include "queue-node.hpp"
#include "queue.hpp"

namespace Queue
{
    using namespace QueueNode;

    template <typename T>
    void Queue<T>::enqueue(T value)
    {
        length++;

        Node<T> *node = new Node<T>;
        node->value = value;

        if (head == nullptr)
            head = node;

        if (tail != nullptr)
            tail->next = node;

        tail = node;
    }

    template <typename T>
    T Queue<T>::dequeue()
    {
        if (head == nullptr)
            return T();

        length--;

        Node<T> *headNode = head;
        head = headNode->next;
        headNode->next = nullptr;

        if (length == 0)
            tail = nullptr;

        return headNode->value;
    }

    template <typename T>
    T Queue<T>::peek()
    {
        if (head == nullptr)
            return T();

        return head->value;
    }
};