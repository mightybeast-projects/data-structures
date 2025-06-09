#pragma once
#include "binary-tree.hpp"

namespace btdfs
{
    template <typename T>
    bool btdfs(binaryTree::BinaryTree<T> tree, T value);
}

namespace
{
    template <typename T>
    bool btdfsRecurse(binaryTreeNode::Node<T> *node, T value);
}

#include "bt-dfs.tpp"