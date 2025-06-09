#pragma once

namespace queueNode
{
    template <typename T>
    struct Node
    {
        T value;
        Node<T> *next = nullptr;
    };
};