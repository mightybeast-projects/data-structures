#include "linked-list.hpp"

namespace linkedList
{
    template <typename T>
    void LinkedList<T>::append(T value)
    {
        length++;

        Node<T> *node = new Node<T>;
        node->value = value;

        if (head == nullptr)
        {
            head = node;
            tail = node;
            return;
        }

        node->prev = tail;
        tail->next = node;
        tail = node;
    }

    template <typename T>
    void LinkedList<T>::prepend(T value)
    {
        length++;

        Node<T> *node = new Node<T>;
        node->value = value;

        if (head == nullptr)
        {
            head = node;
            tail = node;
            return;
        }

        node->next = head;
        head->prev = node;
        head = node;
    }

    template <typename T>
    void LinkedList<T>::insertAt(int index, T value)
    {
        if (indexOutOfBounds(index))
            return;

        if (index == 0)
            return prepend(value);
        if (index == length - 1)
            return append(value);

        length++;

        Node<T> *node = new Node<T>;
        node->value = value;

        Node<T> *nextNode = getAt(index);
        Node<T> *prevNode = nextNode->prev;

        prevNode->next = node;
        node->prev = prevNode;

        nextNode->prev = node;
        node->next = nextNode;
    }

    template <typename T>
    T LinkedList<T>::get(int index)
    {
        if (indexOutOfBounds(index))
            return T();

        return getAt(index)->value;
    }

    template <typename T>
    T LinkedList<T>::removeAt(int index)
    {
        if (indexOutOfBounds(index))
            return T();

        return removeNode(getAt(index));
    }

    template <typename T>
    T LinkedList<T>::remove(T value)
    {
        Node<T> *node = head;

        while (node != nullptr && node->value != value)
            node = node->next;

        if (node == nullptr)
            return T();

        return removeNode(node);
    }

    template <typename T>
    Node<T> *LinkedList<T>::getAt(int index)
    {
        Node<T> *node = head;

        for (int i = 0; i < index; i++)
            node = node->next;

        return node;
    }

    template <typename T>
    T LinkedList<T>::removeNode(Node<T> *node)
    {
        length--;

        if (length == 0)
        {
            head = nullptr;
            tail = nullptr;
            return node->value;
        }

        Node<T> *prevNode = node->prev;
        Node<T> *nextNode = node->next;

        if (nextNode != nullptr)
            nextNode->prev = prevNode;

        if (prevNode != nullptr)
            prevNode->next = nextNode;

        if (head == node)
            head = nextNode;

        if (tail == node)
            tail = prevNode;

        T value = node->value;

        delete node;

        return value;
    }

    template <typename T>
    bool LinkedList<T>::indexOutOfBounds(int index)
    {
        return index < 0 || index >= length;
    }
}
