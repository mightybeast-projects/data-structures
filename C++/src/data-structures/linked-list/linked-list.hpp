#pragma once
#include "linked-list-node.hpp"

namespace linkedList
{
    using namespace linkedListNode;

    template <typename T>
    class LinkedList
    {
    public:
        Node<T> *head = nullptr;
        Node<T> *tail = nullptr;
        int length = 0;

        void append(T value);
        void prepend(T value);
        void insertAt(int index, T value);
        T get(int index);
        T removeAt(int index);
        T remove(T value);

    private:
        Node<T> *getAt(int index);
        T removeNode(Node<T> *node);
        bool indexOutOfBounds(int index);
    };
}

#include "linked-list.tpp"