#pragma once

#include "binary-tree.hpp"

namespace btDFS
{
    using namespace binaryTree;

    template <typename T>
    struct BTDFS
    {
        bool btdfs(BinaryTree<T> tree, T value);

    private:
        bool btdfsRecurse(Node<T> *node, T value);
    };

}

#include "bt-dfs.tpp"