#pragma once

namespace linkedList
{
    template <typename T>
    struct Node
    {
        T value;
        Node<T>* next = nullptr;
        Node<T>* prev = nullptr;

        Node(T val) : value(val) { };
    };

    template <typename T>
    struct LinkedList
    {
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
        int length = 0;

        void append(T value);
        void prepend(T value);
        void insertAt(int index, T value);
        T get(int index);
        T removeAt(int index);
        T remove(T value);

    private:
        Node<T>* getAt(int index);
        T removeNode(Node<T>* node);
        bool indexOutOfBounds(int index);
    };
}

#include "linked-list.tpp"