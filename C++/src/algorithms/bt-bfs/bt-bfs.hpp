#pragma once

#include "binary-tree.hpp"

namespace btBFS
{
    using namespace binaryTree;

    template <typename T>
    bool btbfs(BinaryTree<T> tree, T value);
}

#include "bt-bfs.tpp"
