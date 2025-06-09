#pragma once
#include "binary-tree.h"
#include "queue.h"

namespace BTBFS
{
    template <typename T>
    bool btBFS(BinaryTree::BinaryTree<T> tree, T value);
}

#include "bt-bfs.tpp"
