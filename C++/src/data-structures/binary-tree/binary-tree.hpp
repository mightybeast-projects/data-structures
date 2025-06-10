#pragma once

#include <vector>

namespace binaryTree
{
    template <typename T>
    struct Node
    {
        T value;
        Node<T> *left = nullptr;
        Node<T> *right = nullptr;
    };

    template <typename T>
    struct BinaryTree
    {
        Node<T> *root = nullptr;
        std::vector<T> btPreOrderTraversal();
        std::vector<T> btInOrderTraversal();
        std::vector<T> btPostOrderTraversal();

    private:
        std::vector<T> preOrderRecurse(Node<T> *node, std::vector<T> arr);
        std::vector<T> inOrderRecurse(Node<T> *node, std::vector<T> arr);
        std::vector<T> postOrderRecurse(Node<T> *node, std::vector<T> arr);
    };
}

#include "binary-tree.tpp"