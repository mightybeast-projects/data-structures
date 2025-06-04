#include "stack-node.h"
#include "stack.h"

namespace Stack
{
    using namespace StackNode;

    template <typename T>
    Stack<T>::Stack() {}

    template <typename T>
    void Stack<T>::push(T value)
    {
        length++;

        Node<T> *node = new Node<T>;
        node->value = value;

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

        Node<T> *head = this->head;
        this->head = head->prev;

        return head->value;
    }

    template <typename T>
    T Stack<T>::peek()
    {
        if (head == nullptr)
            return T();

        return head->value;
    }
}