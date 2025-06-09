#pragma once

namespace QueueNode
{
    template <typename T>
    struct Node
    {
        T value;
        Node<T> *next = nullptr;
    };
};