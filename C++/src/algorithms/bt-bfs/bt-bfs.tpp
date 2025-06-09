#include "bt-bfs.hpp"
#include "binary-tree.hpp"
#include "queue.hpp"

namespace btBFS
{
    using namespace binaryTree;

    template <typename T>
    bool btbfs(BinaryTree<T> tree, T value)
    {
        queue::Queue<binaryTree::Node<T>> q;
        q.enqueue(*tree.root);

        while (q.length > 0)
        {
            binaryTree::Node<T> node = q.dequeue();

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