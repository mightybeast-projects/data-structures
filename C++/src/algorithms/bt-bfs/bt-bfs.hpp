#pragma once
#include "binary-tree.hpp"
#include "queue.hpp"

namespace BTBFS
{
    template <typename T>
    bool btBFS(BinaryTree::BinaryTree<T> tree, T value);
}

#include "bt-bfs.tpp"
