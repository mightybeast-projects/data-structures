#include "binary-tree.h"
#include "queue.h"

namespace BTBFS
{
    template <typename T>
    bool btBFS(BinaryTree::BinaryTree<T> tree, T value)
    {
        Queue::Queue<BinaryTreeNode::Node<T>> q;
        q.enqueue(*tree.root);

        while (q.length > 0)
        {
            BinaryTreeNode::Node<T> node = q.dequeue();

            if (node.value == value)
                return true;

            if (node.left != nullptr)
                q.enqueue(*node.left);

            if (node.right != nullptr)
                q.enqueue(*node.right);
        }

        return false;
    }
}
