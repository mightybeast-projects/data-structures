#pragma once

#include "binary-tree.hpp"

namespace btBFS
{
    template <typename T> bool btbfs(binaryTree::BinaryTree<T> tree, T value);
}

#include "bt-bfs.tpp"
