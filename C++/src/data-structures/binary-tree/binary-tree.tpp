#include "binary-tree.hpp"
#include <vector>

namespace binaryTree
{
    using namespace std;

    template <typename T> vector<T> BinaryTree<T>::btPreOrderTraversal()
    {
        return preOrderRecurse(root, vector<T> {});
    }

    template <typename T> vector<T> BinaryTree<T>::btInOrderTraversal()
    {
        return inOrderRecurse(root, vector<T> {});
    }

    template <typename T> vector<T> BinaryTree<T>::btPostOrderTraversal()
    {
        return postOrderRecurse(root, vector<T> {});
    }

    template <typename T>
    vector<T> BinaryTree<T>::preOrderRecurse(Node<T>* node, vector<T> arr)
    {
        arr.push_back(node->value);

        if (node->left != nullptr)
            arr = preOrderRecurse(node->left, arr);
        if (node->right != nullptr)
            arr = preOrderRecurse(node->right, arr);

        return arr;
    }

    template <typename T>
    vector<T> BinaryTree<T>::inOrderRecurse(Node<T>* node, vector<T> arr)
    {
        if (node->left != nullptr)
            arr = inOrderRecurse(node->left, arr);

        arr.push_back(node->value);

        if (node->right != nullptr)
            arr = inOrderRecurse(node->right, arr);

        return arr;
    }

    template <typename T>
    vector<T> BinaryTree<T>::postOrderRecurse(Node<T>* node, vector<T> arr)
    {
        if (node->left != nullptr)
            arr = postOrderRecurse(node->left, arr);
        if (node->right != nullptr)
            arr = postOrderRecurse(node->right, arr);

        arr.push_back(node->value);

        return arr;
    }
}