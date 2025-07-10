#pragma once

#include "binary-tree.hpp"

namespace btDFS
{
    template <typename T> struct BTDFS
    {
        bool btdfs(binaryTree::BinaryTree<T> tree, T value);

    private:
        bool btdfsRecurse(binaryTree::Node<T>* node, T value);
    };

}

#include "bt-dfs.tpp"