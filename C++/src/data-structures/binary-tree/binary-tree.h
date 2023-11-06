using namespace std;

template <typename T>
struct Node
{
    T value;
    Node<T> *left = nullptr;
    Node<T> *right = nullptr;
};

template <typename T>
class BinaryTree
{
public:
    Node<T> *root;

    vector<T> btPreOrderTraversal()
    {
        return preOrderRecurse(root, vector<T>{});
    }

    vector<T> btInOrderTraversal()
    {
        return inOrderRecurse(root, vector<T>{});
    }

    vector<T> btPostOrderTraversal()
    {
        return postOrderRecurse(root, vector<T>{});
    }

private:
    vector<T> preOrderRecurse(Node<T> *node, vector<T> arr)
    {
        arr.push_back(node->value);

        if (node->left != nullptr)
            arr = preOrderRecurse(node->left, arr);
        if (node->right != nullptr)
            arr = preOrderRecurse(node->right, arr);

        return arr;
    }

    vector<T> inOrderRecurse(Node<T> *node, vector<T> arr)
    {
        if (node->left != nullptr)
            arr = inOrderRecurse(node->left, arr);

        arr.push_back(node->value);

        if (node->right != nullptr)
            arr = inOrderRecurse(node->right, arr);

        return arr;
    }

    vector<T> postOrderRecurse(Node<T> *node, vector<T> arr)
    {
        if (node->left != nullptr)
            arr = postOrderRecurse(node->left, arr);
        if (node->right != nullptr)
            arr = postOrderRecurse(node->right, arr);

        arr.push_back(node->value);

        return arr;
    }
};