#pragma once
#include "queue-node.hpp"

namespace Queue
{
    using namespace QueueNode;

    template <typename T>
    class Queue
    {
    public:
        int length = 0;
        Node<T> *head = nullptr;
        Node<T> *tail = nullptr;

        void enqueue(T value);
        T dequeue();
        T peek();
    };
};

#include "queue.tpp"