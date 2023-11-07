#include "binary-tree.h"
#include <queue>

namespace BTBFS
{
    using namespace BinaryTreeNode;

    template <typename T>
    bool btBFS(BinaryTree::BinaryTree<T> tree, T value)
    {
        std::queue<Node<T>> q;
        q.push(*tree.root);

        while (q.size() > 0)
        {
            Node<T> node = q.front();
            q.pop();

            if (node.value == value)
                return true;

            if (node.left != nullptr)
                q.push(*node.left);

            if (node.right != nullptr)
                q.push(*node.right);
        }

        return false;
    }
}
