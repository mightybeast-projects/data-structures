#pragma once

namespace binaryTreeNode
{
    template <typename T>
    struct Node
    {
        T value;
        Node<T> *left = nullptr;
        Node<T> *right = nullptr;
    };
}