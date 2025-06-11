#include "stack.hpp"

namespace stack
{
    template <typename T>
    void Stack<T>::push(T value)
    {
        length++;

        Node<T> *node = new Node<T>(value);

        if (head == nullptr)
        {
            head = node;
            return;
        }

        node->prev = head;
        head = node;
    }

    template <typename T>
    T Stack<T>::pop()
    {
        if (head == nullptr)
            return T();

        length--;

        Node<T> *oldHead = this->head;
        auto value = oldHead->value;

        this->head = oldHead->prev;

        delete oldHead;

        return value;
    }

    template <typename T>
    T Stack<T>::peek()
    {
        if (head == nullptr)
            return T();

        return head->value;
    }
}