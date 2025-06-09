#pragma once
#include "binary-tree.h"

namespace BTDFS
{
    template <typename T>
    bool btDFS(BinaryTree::BinaryTree<T> tree, T value);
}

namespace
{
    template <typename T>
    bool btDFSRecurse(BinaryTreeNode::Node<T> *node, T value);
}

#include "bt-dfs.tpp"