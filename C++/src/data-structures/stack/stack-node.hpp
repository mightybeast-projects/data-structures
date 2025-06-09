#pragma once

namespace stackNode
{
    template <typename T>
    struct Node
    {
        T value;
        Node<T> *prev = nullptr;
    };
}