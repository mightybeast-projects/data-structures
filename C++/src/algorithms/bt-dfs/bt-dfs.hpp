#pragma once
#include "binary-tree.hpp"

using namespace binaryTree;

namespace btdfs
{
    template <typename T>
    bool btdfs(BinaryTree<T> tree, T value);
}

namespace
{
    template <typename T>
    bool btdfsRecurse(Node<T> *node, T value);
}

#include "bt-dfs.tpp"