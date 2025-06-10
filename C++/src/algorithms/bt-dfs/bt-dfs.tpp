#include "bt-dfs.hpp"
#include "binary-tree.hpp"

namespace btDFS
{
    using namespace binaryTree;

    template <typename T>
    bool BTDFS<T>::btdfs(BinaryTree<T> tree, T value)
    {
        return btdfsRecurse(tree.root, value);
    }

    template <typename T>
    bool BTDFS<T>::btdfsRecurse(Node<T> *node, T value)
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