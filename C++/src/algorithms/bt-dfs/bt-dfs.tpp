#include "bt-dfs.hpp"

namespace
{
    template <typename T>
    bool btdfsRecurse(Node<T> *node, T value);
}

namespace btdfs
{
    template <typename T>
    bool btdfs(BinaryTree<T> tree, T value)
    {
        return btdfsRecurse(tree.root, value);
    }
}

namespace
{
    template <typename T>
    bool btdfsRecurse(Node<T> *node, T value)
    {
        if (node == nullptr)
            return false;

        if (node->value == value)
            return true;

        if (node->value < value)
            return btdfsRecurse(node->right, value);

        return btdfsRecurse(node->left, value);
    }
}