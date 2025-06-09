#include "bt-dfs.hpp"

namespace btdfs
{
    template <typename T>
    bool btdfs(binaryTree::BinaryTree<T> tree, T value)
    {
        return btdfsRecurse(tree.root, value);
    }
}

namespace
{
    template <typename T>
    bool btdfsRecurse(binaryTreeNode::Node<T> *node, T value)
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
