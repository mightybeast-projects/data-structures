#pragma once

namespace StackNode
{
    template <typename T>
    struct Node
    {
        T value;
        Node<T> *prev = nullptr;
    };
}