#include "binary-tree.h"

namespace BTDFS
{
    namespace
    {
        template <typename T>
        bool btDFSRecurse(BinaryTreeNode::Node<T> *node, T value)
        {
            if (node == nullptr)
                return false;

            if (node->value == value)
                return true;

            if (node->value < value)
                return btDFSRecurse(node->right, value);

            return btDFSRecurse(node->left, value);
        }
    }

    template <typename T>
    bool btDFS(BinaryTree::BinaryTree<T> tree, T value)
    {
        return btDFSRecurse(tree.root, value);
    }
}