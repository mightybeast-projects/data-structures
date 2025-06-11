#pragma once

namespace queue
{
    template <typename T>
    struct Node
    {
        T value;
        Node<T> *next = nullptr;

        Node(T val) : value(val) {};
    };

    template <typename T>
    struct Queue
    {
        int length = 0;
        Node<T> *head = nullptr;
        Node<T> *tail = nullptr;

        void enqueue(T value);
        T dequeue();
        T peek();
    };
};

#include "queue.tpp"