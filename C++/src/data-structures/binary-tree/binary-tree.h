#pragma once
#include "binary-tree-node.h"

namespace BinaryTree
{
    using namespace std;
    using namespace BinaryTreeNode;

    template <typename T>
    class BinaryTree
    {
    public:
        Node<T> *root;
        vector<T> btPreOrderTraversal();
        vector<T> btInOrderTraversal();
        vector<T> btPostOrderTraversal();

    private:
        vector<T> preOrderRecurse(Node<T> *node, vector<T> arr);
        vector<T> inOrderRecurse(Node<T> *node, vector<T> arr);
        vector<T> postOrderRecurse(Node<T> *node, vector<T> arr);
    };
}

#include "binary-tree.tpp"